#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
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

void solve() {
    int n; cin >> n;
    vi cao(n), rong(n);
    vi dpLen(n), dpXuong(n), rongLen(n), rongXuong(n);

    FOR(n) cin >> cao[i];
    FOR(n) cin >> rong[i];

    FOR(i, n-1, -1, -1) {
        FOR(j, i+1, n, 1) {
            dpLen[i] = dpXuong[i] = 1;
            rongLen[i] = rongXuong[i] = rong[i];
            if (cao[i] < cao[j]) {
                if (dpLen[i] == dpLen[j]+1) {
                    rongLen[i]= max(rongLen[i], rongLen[j]+rong[i]);
                } else if (dpLen[i] < dpLen[j]+1) {
                    dpLen[i] = dpLen[j]+1;
                    rongLen[i] = rongLen[j]+rong[i];
                }
            }
            if (cao[i] > cao[j]) {
                if (dpXuong[i] == dpXuong[j]+1) {
                    rongXuong[i] = max(rongXuong[i], rongXuong[j]+rong[i]);
                } else if (dpXuong[i] < dpXuong[j]+1) {
                    dpXuong[i] = dpXuong[j]+1;
                    rongXuong[i] = rongXuong[j] + rong[i];
                }
            }
        }
    }
    int maxLen, maxXuong;
    int maxRLen, maxRXuong;
    maxLen = maxXuong = 0;
    FOR(n) {
        if (dpLen[i] > maxLen) {
            maxLen = dpLen[i];
            maxRLen = rongLen[i];
        } else if (dpLen[i] == maxLen) {
            maxRLen = max(maxRLen, dpLen[i]);
        }
        if (dpXuong[i] > maxXuong) {
            maxXuong = dpXuong[i];
            maxRXuong = rongXuong[i];
        } else if (dpXuong[i] == maxXuong) {
            maxRXuong = max(maxRXuong, dpXuong[i]);
        }
    }
    if (maxRLen >= maxRXuong) {
        cout << "Increasing (" << maxRLen << "). Decreasing (" << maxRXuong << ").\n";
    }
    else {
        cout << "Decreasing (" << maxRXuong << "). Increasing (" << maxRLen << ").\n";
    }
}

int main()
{
    IOS;
    int t; cin >> t;
    FOR(t) {
        cout << "Case " << i+1 << ". ";
        solve();
    }
}