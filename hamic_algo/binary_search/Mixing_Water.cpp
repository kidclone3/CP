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

void solve(){
    ll h, c, t;
    cin >> h >> c >> t;
    // My error was too much lay on implementation, but not see the real calculus behind this problem.
    // My implementation about binary search is wrong by all side, but I still wasted time to implement it :((
    if (h + c - 2 * t >= 0) return void(cout << 2 <<'\n');
    else {
        // (k+1)*h + k*c = (2*k+1)*t
        // k(2*t-h-c) = h-t
        // k = (2*t-h-c)/(h-t)
        ll a = h-t;
        ll b = 2*t - c - h;
        ll k = 2* (a / b) + 1; // we find the upperbound and lowerbound of real K. 
        // this k is 2*k+1 above
        ll val1 = abs((k+1)/2*h + k/2 * c - k * t);
        ll val2 = abs((k+3)/2*h + (k+2)/2 * c - (k+2)*t);
        cout << (val1 * (k+2) <= val2 * k ? k : k+2) << "\n";
    }
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}