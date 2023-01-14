#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x == 2) return true;
    if (x < 2 || !(x&1)) return false;
    for(int i = 3; i*i <= x; i += 2) if (x % i == 0) return false;
    return true;
}

const int N = 1e6+5;
vector<int> prime;
vector<int> lpf(N, 2);

void sieve() {
    prime.push_back(2);
    lpf[1] = -2;
    for(int i = 3; i <= N; i+=2) {
        if (lpf[i] == 2) prime.push_back(lpf[i] = i);
        for(int j = 0; j < (int) prime.size() && prime[j]*i <= N && prime[j] <= lpf[i]; ++j) 
            lpf[prime[j]*i] = prime[j];
    }
}

int solve(int n, int k, vector<int> &a) {
    int gcd = 0;
    for (int i = 0; i < n; ++i) gcd = __gcd(a[i], gcd);
    if (isPrime(gcd)) {
        return (k/gcd) * gcd;
    } else {
        int ans = 0;
        sieve();
        for(auto &it : prime) {
            if (gcd % it == 0) {
                ans = max(ans, (k/it) * it);
            }
        }
        return ans;
    }
    return 0;
}

int main(int argc, char **argv) {
    int n,k;
    cin >> n>>k;
    vector<int> a(n);
    for (int i=0; i<n; ++i) std::cin >> a[i];
    cout << solve(n, k, a);
}
