#!/bin/bash

git clone https://github.com/catchorg/Catch2.git
cd Catch2
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo env "PATH=$PATH" cmake --build build/ --target install 

cd ../

set -euo pipefail

mkdir -p build && cd build

# Configure
cmake -DCODE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ..
# Build (for Make on Unix equivalent to `make -j $(nproc)`)
cmake --build . --config Debug -- -j $(nproc)
# Test
ctest -j $(nproc) --output-on-failure

