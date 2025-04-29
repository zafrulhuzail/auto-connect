cmake_minimum_required(VERSION 3.12)
project(automotive-connectivity-daemon VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)

# Find dependencies
find_package(Threads REQUIRED)
find_path(SECCOMP_INCLUDE_DIR NAMES seccomp.h)
find_library(SECCOMP_LIBRARY NAMES seccomp)

if(NOT SECCOMP_INCLUDE_DIR OR NOT SECCOMP_LIBRARY)
    message(FATAL_ERROR "libseccomp development files not found! Install with: sudo apt-get install libseccomp-dev")
endif()

# Single executable definition
add_executable(connectivity-daemon
    src/daemon.cpp
    src/power_mgmt.cpp
    src/security.cpp
    src/networking.cpp
)

# Include directories
target_include_directories(connectivity-daemon PRIVATE 
    ${SECCOMP_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(connectivity-daemon PRIVATE
    Threads::Threads
    ${SECCOMP_LIBRARY}
)
