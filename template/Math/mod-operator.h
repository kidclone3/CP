long long addMod(long long a, long long b, long long m) {return ((a+b) % m + m) % m;}

long long mulMod(long long a, long long b, long long m) {
    long long res = 0;
    for (a %= m, b %= m; b > 0; a = addMod(a, a, m), b >>= 1) 
        if (b & 1) res = addMod(res, a, m);
    return res;
}

long long powMod(long long a, long long n, long long m) {
    long long res = 1;
    for (a %= m; n > 0; a = mulMod(a, a, m), n >>= 1) 
        if (n & 1) res = mulMod(res, a, m);
    return res;
}
long long powMod2(long long a, long long n, long long m) {
    long long res = 1;
    for (a %= m; n > 0; a = a*a % m, n >>= 1) 
        if (n & 1) res = res * a % m;
    return res;
}
