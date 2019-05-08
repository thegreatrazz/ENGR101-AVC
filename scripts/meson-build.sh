#!/bin/bash

path=$1
if [ -z "$path" ]; then
  path=avcproj
fi

cd $path && 
meson build &&
cd build &&
ninja
