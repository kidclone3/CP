#!/bin/zsh
# prepare
g++ -std=c++11 -o a1 FenwickTree.cpp
g++ -std=c++11 -o a2 SegmentTree.cpp
g++ -std=c++11 -o a3 SegmentTree2.cpp

echo "FenwickTree measure= "
start_time=$(date +%s)
for i in {0..1000}; do
    ./a1 "data/1e3/1e3_$i.txt" \
        "output/fenwick/1e3/1e3_$i.out" \
        "cerr/fenwick/1e3.txt"
done
for i in {0..1000}; do
    ./a1 "data/1e5/1e5_$i.txt" \
        "output/fenwick/1e5/1e5_$i.out" \
        "cerr/fenwick/1e5.txt"
done
echo "Done"
end_time=$(date +%s)
elapsed=$((end_time - start_time))
echo "Measure time = $elapsed"
#--------------------------------------
echo "Fast Segment tree measure = "
start_time=$(date +%s)

for i in {0..1000}; do
    ./a2 "data/1e3/1e3_$i.txt" \
        "output/fast_st/1e3/1e3_$i.out" \
        "cerr/fast_st/1e3.txt"
done
for i in {0..1000}; do
    ./a2 "data/1e5/1e5_$i.txt" \
        "output/fast_st/1e5/1e5_$i.out" \
        "cerr/fast_st/1e5.txt"
done
echo "Done"
end_time=$(date +%s)
elapsed=$((end_time - start_time))
echo "Measure time = $elapsed"

#--------------------------------------

echo "Normal Segment tree measure= "
start_time=$(date +%s)
for i in {0..1000}; do
    ./a3 "data/1e3/1e3_$i.txt" \
        "output/slow_st/1e3/1e3_$i.out" \
        "cerr/slow_st/1e3.txt"
done
for i in {0..1000}; do
    ./a3 "data/1e5/1e5_$i.txt" \
        "output/slow_st/1e5/1e5_$i.out" \
        "cerr/slow_st/1e5.txt"
done

echo "Done"
end_time=$(date +%s)
elapsed=$((end_time - start_time))
echo "Measure time = $elapsed"
