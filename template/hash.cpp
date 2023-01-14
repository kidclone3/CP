#define long long long
const int N = 1000006, BASE = 1000000007;
int m, n;
char a[N], b[N];
long A[N], B[N], M[N];

void hash_build(char a[], int n, long H[]) {
    for (int i = 1; i <= n; i++)
        H[i] = (H[i - 1] * M[1] + a[i]) % BASE;
}

long hash_range(long H[], int L, int R) {
    return (H[R] - H[L - 1] * M[R - L + 1] + 1LL * BASE * BASE) % BASE;
}

// https://sites.google.com/site/kc97ble/1-3-day-so-va-xau/hash

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};