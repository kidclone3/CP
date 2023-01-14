#include <bits/stdc++.h>
using namespace std;

#define FOR(n) for (int i = 0; i < (n); ++i)

long long mn = LLONG_MAX;
int n;
bool c[20 + 5];
long long a[20 + 5];
long long sum = 0;


int main()
{
    cin >> n;
    FOR(n)
    {
        cin >> a[i];
        sum += a[i];
    }
    
    for (int bit = 1; bit < (1<<n); ++bit) {
        // tao 1 cai mask 1010101
        // Cac day tu 1 den 2^n
        long long tmp = 0LL;
        for (int i = 0; i < 21; ++i) {
            if (bit & (1<<i)) {
                tmp += a[i];
            }
        }
        mn = min(mn, abs(sum - 2*tmp));
    }
    // bitmask

    cout << mn;
}