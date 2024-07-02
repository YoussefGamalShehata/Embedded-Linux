#!/bin/bash
cd ~
mkdir myDirectory
cd myDirectory/
mkdir secondDirectory
cd secondDirectory/
touch myNotePaper
cp myNotePaper ~/myDirectory
cd ..
mv myNotePaper myOldNotePaper