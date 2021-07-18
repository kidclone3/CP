cat '' > out

for (( i = 0; i < 10; i++)) {
    python watershed.py >> out
}