#include <iostream>
#include <atomic>

// this prevents busy polling.
static void yield()
{
    #if defined(__x86_64__) || defined(__i386__)
    #include <emmintrin.h>
    _mm_pause(); // for x86, yield for 10 ~ 140 cycles.
    #elif defined(__aarch64__) || defined(__arm__)
    __asm__ volatile("yield" ::: "memory");
    #endif
}

class lock {
private:
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
public:
    lock() = default;
    lock(const lock &) = delete;
    lock(const lock &&) = delete;
    lock & operator=(const lock &) = delete;
    lock & operator=(const lock &&) = delete;

    void lock_up() {
        while (flag.test_and_set(std::memory_order_acquire)) {
            // if flag is true, some other thread is holding it, this call will return true and keep spinning.
            // only if the flag is false, this call will obtain the lock, return false and break out the loop.
            yield();
        }
    }

    // user is required to lock and unlock it in sequence. Better use RAII.
    void unlock() {
        flag.clear(std::memory_order_release);
    }
};

class lockguard {
private:
    lock & m_lock; // the best way to implement this is a reference member, it does not own the lock, but acts as a pure RAII wrapper.
public:
    lockguard(lock & input): m_lock{input} {
        m_lock.lock_up();
    };
    lockguard(const lock &) = delete;
    lockguard(const lock &&) = delete;
    lock & operator=(const lock &) = delete;
    lock & operator=(const lock &&) = delete;
    ~lockguard() {
        m_lock.unlock();
    };
};