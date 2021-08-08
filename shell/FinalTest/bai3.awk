BEGIN {dem=0}
{
    dem = dem + 1
    # i = index($2, "_")
    # ans = substr($2, 0, i-1)
    # print ans
    if ($3 == "nu")
    {
        print $0
    }
}
END{}