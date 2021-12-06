#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3")

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define sz (int)(x).size()
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

const int N = 1e6 + 5;
vi prime;
vi lpf; //lowest prime factor

void sieve() {
    prime.assign(1, 2);
    lpf.assign(N+1, 2);

    lpf[1] = -2;
    for (int i = 3; i <= N; i += 2) {
        if (lpf[i] == 2) prime.push_back(lpf[i] = i); // which has lpf = 2 also prime itself
        for (int j = 0; j < (int) prime.size() && prime[j] <= lpf[i] && prime[j] * i <= N; ++j) {
            lpf[prime[j]*i] = prime[j];
        }
    }
}

int G[N];

void solve(){
    int n; cin >> n;
    bool ok = false;
    memset(G, 0, sizeof G);
    FOR(i, 2*n) {
        int x; cin >> x;
        if (ok) continue;
        while(x > 1) {
            int p = lpf[x], f = 0;
            do x /= p, ++f;
            while (lpf[x] == p);
            if (p == 2 || p == 5) continue;
            if (i < n) 
                G[p] -= f;
            else {
                G[p] += f;
                if (G[p] > 0) {// f[p] - d[p] > 0 
                    ok = true;
                    break;
                }
            }
        }
    }
    cout << (ok ? "repeating" : "finite") << "\n";
}

int main()
{
    IOS;
    sieve();
    int t; cin >> t;
    while(t--) solve();
}