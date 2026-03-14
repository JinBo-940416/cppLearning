#include <iostream>
#include <atomic>
#include <cstddef>

struct example_aligned_16B {
    char c1;
    char c2;
    short s;
    int i;
    int j;
    int k;
};

struct example_aligned_17B {
    char c1;
    char c2;
    short s;
    int i;
    int j;
    int k;
    char c3;
};

struct example_aligned_20B {
    char c1;
    char c2;
    short s;
    int i;
    int j;
    int k;
    int l;
};

struct example_misaligned_16B {
    short s;
    char c1;
    int i;
    char c2;
    int j;
    int k;
};

struct example_aligned_8B
{
    int a;
    int b;
};

struct example_misaligned_8B
{
    int a;
    char b;
    short c;
    char d;
};

template<typename T>
void lock_check(T& a)
{
    std::cout << "Now checking " << typeid(T).name() << ", is_lock_free: " << a.is_lock_free() << std::endl;
}

void check_word_size()
{
    int *a = nullptr;
    std::cout << " word size on this device is : " << sizeof(a) << std::endl;
}

int main(int argc, char **argv) {
    check_word_size();
    std::atomic<char> c;
    lock_check(c);

    std::atomic<short> s;
    lock_check(s);

    std::atomic<int> i;
    lock_check(i);

    std::atomic<long> l;
    lock_check(l);

    std::atomic<long long> ll;
    lock_check(ll);

    std::atomic<float> f;
    lock_check(f);

    std::atomic<double> d;
    lock_check(d);

    std::atomic<int *> ptr;
    lock_check(ptr);

    {
        std::atomic<struct example_aligned_8B> exp;
        std::cout << "checking " << typeid(exp).name() << ", size: " << sizeof(exp) << std::endl;
        lock_check(exp);
    }
    {
        std::cout << "checking misaligned 8B " << ", size: " << sizeof(struct example_misaligned_8B) << std::endl;
        // struct member should align to this member's size.-> 10. Then pad to multiple of largest member, -> 12.
        std::atomic<struct example_misaligned_8B> exp;
        // atomic type, will pad it so that its size is a power of 2.
        std::cout << "checking " << typeid(exp).name() << ", size: " << sizeof(exp) << std::endl;
        lock_check(exp);
    }
    {
        std::atomic<struct example_aligned_16B> exp;
        std::cout << "checking " << typeid(exp).name() << ", size: " << sizeof(exp) << std::endl;
        lock_check(exp);
    }
    {
        std::atomic<struct example_aligned_20B> exp;
        std::cout << "checking " << typeid(exp).name() << ", size: " << sizeof(exp) << std::endl;
        lock_check(exp);
    }
    {
        std::atomic<struct example_aligned_17B> exp;
        std::cout << "checking " << typeid(exp).name() << ", size: " << sizeof(exp) << std::endl;
        lock_check(exp);
    }
    {
        std::atomic<struct example_misaligned_16B> exp;
        std::cout << "checking " << typeid(exp).name() << ", size: " << sizeof(exp) << std::endl;
        lock_check(exp);
    }
    /*
        conclusion:
        as long as struct size is <= 16 bytes after normal padding, the object is lock free, cpu can do a 128 bit atomic.
        atomic types will be padded to power of 2 if can fit within 16 bytes. If cannot, follow normal padding.
    */
    return 0;
}