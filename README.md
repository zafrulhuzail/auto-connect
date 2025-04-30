# 🚗 Automotive Connectivity Daemon

A **simple Linux C++ program** that simulates a car's computer system, demonstrating security, networking, and power management - perfect for beginners!

## 🌟 What This Does
This program acts like a **"brain" for a smart car**, with 3 main jobs:
1. **🔒 Security** - Locks down the system (like a car alarm)
2. **📡 Networking** - Checks internet connections (WiFi/cellular)
3. **🔋 Power Management** - Monitors battery level

## 🛠️ How It Works
| File               | What It Does                          | Real Car Example                 |
|--------------------|---------------------------------------|----------------------------------|
| `daemon.cpp`       | Main controller (like a dashboard)    | Runs everything in a loop        |
| `security.cpp`     | Blocks dangerous actions              | Prevents hacking attacks         |
| `networking.cpp`   | Checks WiFi/cellular connections      | Ensures software updates work    |
| `power_mgmt.cpp`   | Checks battery level                  | Prevents battery drain           |

## 💻 How to Run It
1. **Make sure Docker is installed**
2. Open terminal in this folder and run:
   ```bash
   docker-compose build
   docker-compose run --rm dev
3. Update and install dependencies (inside container/on Ubuntu)
apt-get update && apt-get install -y libseccomp-dev

4. Build fresh
cmake ..
make
5. Run executable file
./connectivity-daemon

## 🛠️ How to clean
1. Clean everything
    ```bash
    rm -rf /workspace/build/*
    cd /workspace
2. Update and install dependencies
    ```bash
    apt-get update && apt-get install -y libseccomp-dev
3. Build fresh
    ```bash 
    mkdir -p build
    cd build
    cmake ..
    make
4. Run executable file
    ```bash
    ./connectivity-daemon