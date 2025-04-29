# 🚗 Automotive Connectivity Daemon

A **simple Linux C++ program** that simulates a car's computer system, demonstrating security, networking, and power management - perfect for beginners!

## 🌟 What This Does
This program acts like a **"brain" for a smart car**, with 3 main jobs:
1. **🔒 Security** - Locks down the system (like a car alarm)
2. **📡 Networking** - Checks internet connections (WiFi/cellular)
3. **🔋 Power Management** - Monitors battery level

## 🛠️ How It Works (For Beginners)
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