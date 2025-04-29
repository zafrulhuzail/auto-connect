#!/bin/bash
# Set up development environment
mkdir -p /workspace/build
cd /workspace/build
cmake ..
make -j$(nproc)
exec bash