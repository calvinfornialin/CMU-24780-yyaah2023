#!/bin/bash

# remove the previous executable
rm -r test.app

# create a new folder for executable
mkdir -p test.app/Contents/MacOS

# compile frameworks
clang -c fssimplewindowobjc.m
clang -c yssimplesound_macosx_objc.m

# Specify the directory to delete and create
build_directory="build"

# Delete the existing directory if it exists
if [ -d "$build_directory" ]; then
  echo "Deleting build directory: $build_directory"
  rm -r "$build_directory"
fi

# Create a new directory
echo "Creating new build directory: $build_directory"
mkdir "$build_directory"

# Move into the directory
cd "$build_directory" || exit

# cmake
cmake ..

# make
make

# move back to the source dir
cd ../

# run the program
test.app/Contents/MacOS/exe