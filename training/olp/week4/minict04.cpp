#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int) (b) : i > (int) (b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
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

const int N = 1e5+5;
vi prime;
vi lpf(N+5, 2);
void sieve() {
    prime.assign(1, 2);
    lpf[1] = -2;
    for(int i = 3; i < N; i+=2) {
        if (lpf[i] == 2) prime.pb(lpf[i] = i);
        for(int j = 0; j < (int) prime.size() && prime[j] <= lpf[i] && i*prime[j] <= N; ++j) {
            lpf[i*prime[j]] = prime[j];
        }
    }
}

int n;
int sum = 0;
int ans = 0;
void backtrack(int i, int cnt) {
    if (sum > n) return;
    if (sum == n) ans = max(ans, cnt);
    FOR(j, i, prime.size()) {
        if (sum + prime[i] > n) break;
        sum += prime[i];
        backtrack(i+1, cnt+1);
        sum -= prime[i];
    }
}

void solve() {
    cin >> n;
    backtrack(0, 0);
    cout << ans;
}

int main()
{
    IOS;
    sieve();
    // cout << lpf[6];
    solve();
}