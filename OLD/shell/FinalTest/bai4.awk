BEGIN {dem = 0}
{
    dem+=1
    if (NR % 2 == 1) {
        print $0
    }
}
END {print dem}
