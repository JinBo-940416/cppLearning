#include "LFQueue.h"

template <typename T>
LFQueue<T>::LFQueue(std::size_t size_min): capacity{raise_to_2_powers(size_min + 1)} , mask{capacity - 1}  // will leave 1 slot for diff empty and full.
{
    T dummy;
    data.reserve(capacity);
    for (int i = 0; i < capacity; ++i) {
        data.push_back(dummy); // warm up ram to avoid page fault.
    }
}

template <typename T>
bool LFQueue<T>::produce(T&& input)
{
    uint32_t current_head = head.load(std::memory_order_relaxed);
    uint32_t next_head = current_head + 1;
    if (next_head == tail.load(std::memory_order_acquire)) { // load the latest value of tail. producer thread will flush invalid queue, revalidate prefetch buffer.
        // the queue is full.
        return false;
    }

    // succeed, head is updated to next_head. 
    uint32_t index = current_head & mask;
    data[index] == std::forward(input);
    head.store(next_head, std::memory_order_release); // finished writing data, then move head index.
    return true;
}

template <typename T>
bool LFQueue<T>::consume(T& output)
{
    uint32_t current_tail = tail.load(std::memory_order_relaxed);
    if (current_tail == head.load(std::memory_order_acquire)) { // need to load the latest value, consumer thread will flush invalid queue, revalidate prefetch buffer.
        // the queue is empty, no entry to consume.
        return false;
    }
    uint32_t next_tail = current_tail + 1;

    // succeed, reserved current_tail index for consumption.
    output = std::move(data[current_tail]);
    tail.store(next_tail, std::memory_order_release); // finished comsuming data, then shift tail index.
    return true;
}

template<typename T>
std::shared_ptr<LFQueue<T>>& get_ring(std::size_t size)
{
    if (size <= 32) {
        size = 32;
    }
    static std::shared_ptr<LFQueue<T>> ring_ptr = std::make_shared<LFQueue<T>>(size);
    return ring_ptr;
}