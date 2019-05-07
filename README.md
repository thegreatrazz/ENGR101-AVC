# Autonomous Vechicle Challenge

## Building

If you are on a Raspberry Pi, just run `build.sh` and you should be golden.

Otherwise, you will certainly need a cross-compiler to ARM Hardfloat (like `arm-linux-gnueabihf-g++`) to make this work.

A version of `E101.h` is included.

## Notes before the project starts
* Compile binary blobs in the cloud (i mean gitlab) on every commit
* Write script for the Raspberry Pi to download the blob whenever