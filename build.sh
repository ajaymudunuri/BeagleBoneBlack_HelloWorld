#! /usr/bin/bash

buildCommand="arm-linux-gnueabihf-gcc"
outputFileName="hello_beagle_bone"
sourceFileName="hello_beagle_bone.c"
objectFilePath="output/obj"

echo "Starting build script from directory : "
pwd
echo "Found the following C source files in the directory..."
ls *.c

mkdir -p $objectFilePath

echo "Building output file $outputFileName..."
$buildCommand $sourceFileName -o $objectFilePath/$outputFileName 
echo "Done"