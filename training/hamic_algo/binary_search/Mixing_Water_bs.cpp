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

double h, c, t;
double f(ll k) {
    
    return (1.0*k*h + (k-1)*c)/(2.0*k-1);
}

void solve(){
    cin >> h >> c >> t;
    if (2*t <= h+c) return void(cout << "2\n");
    ll l = 1, r = 1e9;
    double minDiff = 1e9;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l+r)/2;
        double temp = f(mid) - t;
        if (abs(temp) < minDiff) {
            ans = mid;
            minDiff = abs(temp);
        }
        if (temp > 0) l = mid + 1;
        else r = mid - 1;
    }
    FOR(i, max(0LL, l-5), l+5) {
        double temp = abs(f(i) - t);
        if (temp <= minDiff) {
            ans = min(ans, i*1LL);
            minDiff = temp;
        }
    }
    cout << 2*ans-1 << "\n";

}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}