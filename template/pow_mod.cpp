long long pow_mod(long long a, long long n, long long mod) {
    long long ans = 1LL;
    for (long long i = n; i; i >>= 1) {
        if (i&1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}