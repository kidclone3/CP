#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6+5;

int main() {
    vector<ll> f(N, 0);
    for(int i = 1; i < N; ++i) {
        f[i] = i|(i+1);
        f[i] += f[i-1];
    }
    int q; cin >> q;
    for(int i = 0; i < q; ++ i) {
        int x; cin >> x;
        cout << f[x] << '\n';
    }
}