#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9+7;
ll powMod(ll x, ll n) {
    ll ans = 1LL;
    for(; n; x = x*x % MOD, n >>= 1)
        if (n&1) ans = ans*x % MOD;
    return ans;
}

ll mulMod(ll a, ll b) {
    return (a %MOD) * (b %MOD) % MOD;
}

int xorAndSum(string a, string b) {
    const ll shift_num = 314159+1;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // first = 0 bits, second = 1 bits.
    vector<vector<int>> f_a(a.size(), {0, 0}), f_b(b.size(), {0, 0});

    int a_n = a.size(), b_n = b.size();

    ll aa, bb;
    aa = bb = 0LL;
    for (int i = 0; i < a_n; ++i) {
        // if (a[i] == '0') f_a[i] = {1, 0}; else f_a[i] = {0, 1};
        // if (i) f_a[i].first += f_a[i-1].first, f_a[i].second += f_a[i-1].second;
        if (a[i] == '1') aa = (aa + powMod(2, i)) % MOD;
    }
    for (int i = 0; i < b_n; ++i) {
        if (b[i] == '0') f_b[i] = {1, 0}; else {
            f_b[i] = {0, 1};
        }
        if (i) f_b[i][0]+= f_b[i-1][0], f_b[i][1] += f_b[i-1][1];
    }

    ll ans = 0LL;
    for (int i = 0; i < min(a_n, b_n); ++i) {
        int tmp = a[i] - '0';
        ans = (ans + mulMod(f_b[i][1^tmp], powMod(2, i))) % MOD;
    }
    // Calculate bb from last to one, each time we shift left one.
    // We need a variable base_shifted = |a| - |b| (in case |a| >= |b|)
    // if not? what we will do?
    // Just let that be natural.
    // ok, i got it.
    // We need something to add into.
    int shifted = 0;
    if (a.size() > b.size()) shifted = a.size() - b.size();
    for (int i = b_n-1; i > -1; --i) {
        if (i < a_n) {
            bb = mulMod(bb, 2);
            shifted++;
        }
        if (b[i] == '1') {
            bb = (bb + powMod(2, i + shifted)) % MOD;
            ans = (ans + bb) % MOD;
        } else {
            if (i < a_n) ans = (ans + bb) % MOD;
        }
    }

    // ans = ans + aa * (314159 - a.size())
    // ans = ans + bb * 2^(314159-a.size())


    // bb = mulMod(bb, powMod(2, a.size()));
    cout << ans << '\n' ;
    ans = (ans + mulMod(aa, shift_num - a.size())) % MOD;
    ans = (ans + mulMod(bb, powMod(2, shift_num - a.size()))) % MOD;
    cout << aa << " " << bb << '\n';

    for (auto it : f_b) cout << it[0] << " " << it[1] << "\n";
    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << xorAndSum(a, b);
}
