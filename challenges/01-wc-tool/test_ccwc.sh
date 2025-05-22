#!/bin/bash

# Test script for ccwc
filename=$1
echo -e "\n----------- Testing ccwc on file: $filename -----------\n"

echo -e "----------- Step 1: Test bytes count (-c) -----------" 
# Expected count using system's wc
expected=$(wc -c "$filename")
echo "wc output: $expected"
    
# Actual count using ccwc implementation 
actual=$(./ccwc -c "$filename")
echo "ccwc output: $actual"

echo -e "\n----------- Step 2: Test lines count (-l) -----------" 
# Expected count using system's wc
expected=$(wc -l "$filename")
echo "wc output: $expected"

# Actual count using ccwc implementation 
actual=$(./ccwc -l "$filename")
echo "ccwc output:   $actual"

echo -e "\n----------- Step 3: Test words count (-w) -----------"
# Expected count using system's wc
expected=$(wc -w "$filename")
echo "wc output: $expected"

# Actual count using ccwc implementation 
actual=$(./ccwc -w "$filename")
echo "ccwc output:  $actual"

echo -e "\n----------- Step 4: Test words characters (-m) -----------"
# Expected count using system's wc
expected=$(wc -m "$filename")
echo "wc output: $expected"

# Actual count using ccwc implementation 
actual=$(./ccwc -m "$filename")
echo "ccwc output: $actual"

echo -e "\n----------- Step 5: Test default option -----------"
# Expected count using system's wc
expected=$(wc "$filename")
echo "wc output: $expected"

# Actual count using ccwc implementation 
actual=$(./ccwc "$filename")
echo "ccwc output:   $actual"