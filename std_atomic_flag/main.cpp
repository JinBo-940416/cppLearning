#include "lock.h"
#include <thread>

/*
    only 1 atomic type does not provide a is_lock_free(), the std::atomic_flag type. It is the only type that is guaranteed to be lock free. Others depend on compiler.
    It must be initialized to ATOMIC_FLAG_INIT, and has two member functions:
        1) test_and_set(), -> RMW, try to set as true and return old value.
        2) clear(), -> store operation, set to false, return void.
*/
int counter = 0;
lock counter_lock;

int main(int argc, char **argv) {

    auto task = [](int iterations){
        for (int i = 0; i < iterations; i++) {
            lockguard lg(counter_lock); // if comment out this line, UB.
            counter++;
        }
    };

    std::thread first_thread(task, 5000000);
    std::thread second_thread(task, 6000000);
    std::thread third_thread(task, 7000000);

    first_thread.join();
    second_thread.join();
    third_thread.join();

    std::cout << "counter in the end is: " << counter << std::endl;
    return 0;
}