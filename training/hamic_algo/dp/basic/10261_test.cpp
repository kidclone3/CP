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
#define fi first
#define se second
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

const int MAXLEN = 100*100;

void solve(){
    // int len; cin >> len;

    // len *= 100;

    // vi cars;

    // int in; cin >> in;

    // while(in != 0) {

    //     cars.push_back(in);

    //     cin >> in;

    //
    int len = 5;
    vi cars = {2, 4, 3, 1, 5, 6};
    int n = cars.size();
    vector<vi> f(n+1, vi(2*len+5, 0));
    int m = 0;
    f[0][len] = 1;
    int sum = 0;
    FOR(i, 1, n+1) {
        FOR(j, 1, len + 1) {
            int l2 = 2 * len - j - sum;
            if (cars[i-1] <= j) f[i][j - cars[i-1]] = 1;
            if (cars[i-1] <= l2) f[i][j] = 2;    
        }
        sum += cars[i-1];
        m = i;
        if (sum > 2 * len) break;
    }
    cout << m << "\n";
    // now is trace back
    if (m == 0) return;
    vector<int> trace;
    int l1 = len;
    for(; f[m][l1] == 0; --l1);
    cout << f[m][l1] << " " << l1 << "\n";
    for(; m > 0; --m) {
        trace.push_back(f[m][l1]);
        if (f[m][l1] == 1) l1 += cars[m-1];
        cout << l1 << " ";
    }
    cout << "\n";
    reverse(all(trace));
    print(trace);

}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}