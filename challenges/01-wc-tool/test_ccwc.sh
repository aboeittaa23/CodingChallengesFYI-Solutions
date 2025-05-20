#!/bin/bash

# Test script for ccwc
filename=$1
echo -e "\n----------- Testing ccwc on file: $filename -----------\n"

echo -e "----------- Step 1: Test byte count (-c) -----------" 
# Expected count using system's wc
expected=$(wc -c "$filename")
echo "wc output: $expected"
    
# Actual count using ccwc implementation 
actual=$(./ccwc -c "$filename")
echo "ccwc output: $actual"

echo -e "\n----------- Step 2: Test line count (-l) -----------" 
# Expected count using system's wc
expected=$(wc -l "$filename")
echo "wc output: $expected"

# Actual count using ccwc implementation 
actual=$(./ccwc -l "$filename")
echo "ccwc output:   $actual"

echo -e "\n----------- Step 3: -----------" 