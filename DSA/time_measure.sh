#!/bin/zsh
# prepare
g++-11 -o fenWick FenwickTree.cpp 
g++-11 -o segment1 SegmentTree.cpp 
g++-11 -o segment2 SegmentTree2.cpp

echo "FenwickTree measure= "
./fenwick ""
echo ""
echo "Fast Segment tree measure = "
./a2

echo ""
echo "Normal Segment tree measure= "
./a3
echo ""
