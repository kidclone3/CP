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
        cout << it.first << " " << it.second <<"\n";
    }
    cout << "\n";
};
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

bool cmp(const ii A, const ii B) {
    return (A.second != B.second ? A.second < B.second : A.first < B.first);
}

void solve(){
    int n; cin >> n;
    vi a(n+1), dp(n+1);
    dp[0] = 0;
    FOR1(n) {
        cin >> a[i];
        dp[i] = dp[i-1] + a[i];
    }
    map<int, vii> mp;
    FOR(i, 1, n+1) {
        FOR(j, 1, i+1) {
            int sum = dp[i] - dp[j-1];
            mp[sum].push_back({j, i});
        }
    }
    int mx = 0;
    vii ans;
    EACH(it, mp) {
        sort(all(it.second), cmp);
        int upper, lower;
        upper = lower = INT_MIN;
        vii tmp;
        EACH(it2, it.second) {
            if(it2.first > upper) {
                tie(lower, upper) = it2;
                tmp.push_back(it2);
            }
        }
        if (tmp.size() > mx) {
            ans = tmp;
            mx = tmp.size();
        }
    }
    cout << ans.size() << "\n";
    printPair(ans);
}

int main()
{
    IOS;
    solve();
}