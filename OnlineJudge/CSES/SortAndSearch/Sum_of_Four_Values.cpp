#include <bits/stdc++.h>
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
    int n; ll x;
    cin >> n >> x;
    vl a(n);
    FOR(n) {
        cin >> a[i];
    }
    map<ll, ii> mp;
    FOR(i, 0, n-1) {
        FOR(j, i+1, n) {
            mp[a[i]+a[j]] = {i, j};
        }
    }
    FOR(i, 0, n-1) {
        FOR(j, i+1, n) {
            if (mp.find(x-(a[i]+a[j])) != mp.end()) {
                ii tmp = mp[x-a[i]-a[j]];
                if (i != tmp.first && i != tmp.second && j != tmp.first && j != tmp.second) {
                    // vi ans = {i+1, j+1, tmp.first+1, tmp.second+1};
                    vi ans(4);
                    ans[0] = i+1; ans[1] = j+1; ans[2] = tmp.first+1; ans[3] = tmp.second+1;
                    sort(all(ans));
                    print(ans);
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    IOS;
    solve();
}