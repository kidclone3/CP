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

ll n, k;
bool check(ll x) {
    ll ans = 0;
    queue<pair<ll, ll>> q;
    if (x & 1) q.push({x, x});
    else q.push({x, x+1});
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        ans += min(n, it.second) - it.first + 1;
        if (it.first * 2 <= n) q.push({it.first * 2, it.second*2+1});
    }
    return ans >= k;
}

void solve(){
    // this is binary search version;
    cin >> n >> k;
    ll ans = 1;
    ll left = 1, right = n/2;
    // Check even;
    while(left <= right) {
        ll mid = (left+ right) / 2;
        if (check(2*mid))
        {
            ans = max(2*mid, ans);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    // check odd:
    left = 0, right = n/2;
    while(left <= right) {
        ll mid = (left+ right) / 2;
        if (check(2*mid+1))
        {
            ans = max(2*mid+1, ans);
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << ans;
}

int main()
{
    IOS;
    solve();
}