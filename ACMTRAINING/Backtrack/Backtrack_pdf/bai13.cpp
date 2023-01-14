#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int)(b) : i>(int)(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int d4x[] = {-1, 0, 1, 0},
        d4y[] = {0, -1, 0, 1},
        d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
        d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cerr << it << " ";
    }
    cerr << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cerr << "(" << it.first << ", " << it.second <<") ";
    }
    cerr << "\n";
};
int solve() {
    vector<string> grid(4);
    FOR(4) {
        cin >> grid[i];
    }
    int ans = INT_MAX;
    for(int i = 0; i < (1<<16); ++i) {
        vt<vi> b(4, vi(4, 0));
        FOR(i1, 4) 
            FOR(j1, 4)
                if (grid[i1][j1] == 'n') b[i1][j1] = 1;
        for(int j = 0; (1<<j) <= i; ++j) {
            int tmp = i;
            if ((tmp >> j) & 1) {
                int x = j/4;
                int y = j%4;
                b[x][y] = 1 - b[x][y];
                FOR(k, 4) {
                    int xx = x + d4x[k];
                    int yy = y + d4y[k];
                    if (0 <= xx && xx < 4 && 0 <= yy && yy < 4) {

                        b[xx][yy] = 1-b[xx][yy];
                    }
                }
            }
        }
        
        int cnt = 0;
        FOR(i1, 4) FOR(j1, 4) cnt += b[i1][j1];
        if (cnt == 0 || cnt == 16) {
            ans = min(ans, __builtin_popcount(i));
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}
int main() {
    IOS;
// #ifndef ONLINE_JUDGE
// 	freopen("in", "r", stdin);
// 	freopen("out", "w", stdout);
// #else
// 	// online submission
// #endif
    solve();
    // cout << "test";
    return 0; 
}

