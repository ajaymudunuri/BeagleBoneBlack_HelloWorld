#! /usr/bin/bash

buildCommand="arm-linux-gnueabihf-g++"
outputFileName="hello_beagle_bone"
sourceFileName="hello_beagle_bone.cpp"
objectFilePath="output/obj"

echo "Starting build script from directory : "
pwd
echo "Found the following C source files in the directory..."
ls *.cpp

mkdir -p $objectFilePath

echo "Building output file $outputFileName..."
$buildCommand $sourceFileName -o $objectFilePath/$outputFileName 
echo "Done"