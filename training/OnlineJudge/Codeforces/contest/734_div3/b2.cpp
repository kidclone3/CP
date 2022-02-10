#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
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


void solve(){
    int n, k; cin >> n >> k;
    vi a(n), dp(n, -1);
    // map<int, set<int>> mp;
    map<int, int> mp;
    set<pair<int, int>> st[k];
    int sz = 0;
    FOR(n) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] <= k) sz++;
    }
    sz /= k;
    priority_queue<pair<size_t, int>, vector<pair<size_t, int>>, greater<pair<size_t, int>>> pq;
    FOR(k) {
        pq.push({0, i});
    }
    FOR(n) {
        auto tmp = pq.top();
        auto it = st[tmp.second].lower_bound(make_pair(a[i], 0));
        if (it == st[tmp.second].end() || a[i] != it->first) {
            dp[i] = tmp.second + 1;
            st[tmp.second].insert({a[i], i});
        }
        else {
            
        }
    }
    print(dp);
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}