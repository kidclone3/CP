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

vi prime = {2, 3, 5, 7, 11, 13};
// , 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137};

ll n, x = 0LL;
int cnt = 0;

bool check(ll k) {
    string s = to_string(k);
    int ans = 0;
    EACH(it, s) ans += it-'0';
    auto it = lower_bound(all(prime), ans);
    return *it == ans;
}

set<ll> c;

void backtrack(int i, int left) {
    if (i > 15) return;
    // if(x >= n) return;
    if (left < 0) return;
    if (left == 0) {
        // c.push_back(x);
        // c.insert(x);
        // cout << x <<" ";
        cnt++;
    }
    for(int j = 0; j <= 9; ++j) {
        if (!i && !j) continue;        
        if (left - j < 0) break;
        x *= 10;
        x += j;
        backtrack(i+1, left - j);
        x /= 10;
    }
}

void solve() {
    // cin >> n;    
    // cout << n;
    // backtrack(0, 2);
    // FOR(i, 0, 21) {
        // n = i;
        x = 0LL;
        EACH(it, prime) {
            cnt = 0LL;
            backtrack(0, it);        
            cout << cnt << "\n";
        }
        // print(c);
        // cout << cnt << ", ";
        
    // }
}

int main()
{
    IOS;
    solve();
}