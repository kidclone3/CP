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
    int n; char ch;
    cin >> n >> ch;
    string s; cin >> s;
    if (count(all(s), ch) == n) return void(cout << "0\n");
    if (s[n-1] == ch) {
        return void(cout << "1\n" << n << "\n");
    }

    vi b;
    FOR(i, n/2+1, n) {
        if (s[i] == ch) {
            return void(cout << "1\n" << i+1 << "\n");
        }
        
    }
    FOR(i, 0, n/2) {
        if (s[i] != ch) b.push_back(i+1);
    }
    FOR(i, n/2, -1, -1) {
        if (s[i] == ch) {
            bool check = true;
            EACH(it, b) if (it % (i+1) == 0) {
                check = false;
                break;
            }
            if (check) return void(cout << "1\n" << i+1 << "\n");
        }
    }
    return void(cout << "2\n" << n << " " << n-1 << "\n");
    
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}