#!/bin/zsh
# prepare
g++-11 -o a1 FenwickTree.cpp 
g++-11 -o a2 SegmentTree.cpp 
g++-11 -o a3 SegmentTree2.cpp

echo "FenwickTree measure= "
./a1
echo ""
echo "Fast Segment tree measure = "
./a2

echo ""
echo "Normal Segment tree measure= "
./a3
echo ""
