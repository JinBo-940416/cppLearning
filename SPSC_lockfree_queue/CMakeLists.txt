cmake_minimum_required(VERSION 3.10)

# Name your project
project(LockFreeQueueProject)

# Set the C++ standard (C++17 is recommended for modern features and hardware interference sizes)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the executable name and list all source and header files
# (Including headers isn't strictly necessary for compiling, but helps IDEs display them)
add_executable(spsc_queue_app
    main.cpp
    utils.cpp
    utils.h
    LFQueue.cpp
    LFQueue.h
)

# Find and link the system thread library required for std::thread and std::atomic
find_package(Threads REQUIRED)
target_link_libraries(spsc_queue_app PRIVATE Threads::Threads)