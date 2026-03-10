#pragma once

#include <cstddef>
#include "utils.h"
#include <vector>
#include <atomic>
#include <memory>

#define CPU_CACHELINE_SIZE 64
#define CPU_CACHE_ALLIGN alignas(CPU_CACHELINE_SIZE)

template <typename T>
class LFQueue {
    std::vector<T> data;
    CPU_CACHE_ALLIGN std::atomic<uint32_t> head;
    CPU_CACHE_ALLIGN std::atomic<uint32_t> tail;
    std::size_t capacity; // upsize min_size to a value closest to 2^n
    std::size_t mask; // capacity - 1, so that this is a bit mask like 0x000000ff
public:
    // default, copy, move cons should all be deleted;
    LFQueue() = delete;
    LFQueue(const LFQueue &) = delete;
    LFQueue(LFQueue &&) = delete;

    // assignment or move operator, not allowed.
    LFQueue & operator=(const LFQueue &) = delete;
    LFQueue & operator=(LFQueue &&) = delete;

    LFQueue(std::size_t min_size); // there should be only 1 way to create this queue. Specify size and create it. 
    bool produce(T&& input); // reference collapse will help do perfect forwarding.
    bool consume(T& output); // caller must use a lvalue reference to catch the entry content.
};

/*
    return static shared ptr of LFQueue of type T. To avoid static initialization order fiasco.
*/
template<typename T>
std::shared_ptr<LFQueue<T>> get_ring(std::size_t size);