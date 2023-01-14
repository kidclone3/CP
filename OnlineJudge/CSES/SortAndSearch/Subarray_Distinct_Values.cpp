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
    ll ans = 0LL;
    int n, k; 
    // cin >> n >> k;
    scanf("%d%d", &n, &k);
    vi a;
    FOR(n) {
        int tmp;
        scanf("%d", &tmp); a.push_back(tmp);
    }
    map<int, int> mp;
    int i = 0;
    ll sz = 0ll;
    for(; i < n; ++i) {
        mp[a[i]]++;
        sz++;
        if ((int) mp.size() > k) {
            mp.erase(a[i]);
            sz--;
            break;
        }
    }
    int last = 0;
    if (i == n) {
        ans = 1LL*n*(n+1)/2;
        // cout << ans;
        printf("%lld\n", ans);
        return;
    }
    else while(last < n && (int) mp.size() == k) {
            ans += sz;
            if (mp[a[last]] == 1) mp.erase(a[last]);
            else {
                mp[a[last]]--;
            }
            sz--;
            last++;
        }
    
    for(; i < n-1; ++i) {
        mp[a[i]]++;
        sz++;
        if ((int)mp.size() == k && mp.find(a[i+1]) == mp.end()) {
            // ans += sz;
            while(last < n && (int) mp.size() == k) {
                ans+=sz;
                if (mp[a[last]] == 1) mp.erase(a[last]);
                else {
                    mp[a[last]]--;
                }
                sz--;
                last++;
            }
            // if (i == n-1) mp.clear();
        }
    }
    sz++;
    ans += sz*(sz+1)/2;
    // cout << ans;
    printf("%lld\n", ans);
}

int main()
{
    IOS;
    solve();
}