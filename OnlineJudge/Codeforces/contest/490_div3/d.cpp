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
    ll n; ll m;
    cin >> n >> m;
    vl a(n);
    map<ll, vi> mp;
    FOR(n) {
        cin >> a[i];
        mp[a[i]%m].push_back(i);
    }

// debug
    // EACH(it, mp) cout << it.first << " " << it.second.size() << "\n";

    // Xoa nhung keu du dieu kien
    queue<ii> thua;
    set<ii> thieu;
    // vi tmp_thieu;
    FOR(it, 0, m) {
        if (mp[it].size() == (n/m)) continue;
        else if (mp[it].size() > (n/m)) thua.push({it, mp[it].size()-(n/m)});
        else {
            thieu.insert({it, -mp[it].size()+(n/m)});
        }
    }
    ll ans = 0ll;
    ii top_thua = {0, 0};
    while(!thua.empty() || !thieu.empty()) {
        if (top_thua.second == 0) {
            top_thua = thua.front();
            thua.pop();
        }
        ii use;
        bool pick_2 = true;
        auto tmp1 = thieu.lower_bound({top_thua.first, 0});
        auto tmp2 = thieu.begin();
        int chenh_lech;
        if (tmp1 == thieu.end()) {
            use = *tmp2;
            chenh_lech = tmp2->first - top_thua.first + m;
        }
        else {
            int chenh_1 = tmp1->first - top_thua.first;
            int chenh_2 = tmp2->first - top_thua.first + m;

            if (chenh_1 < chenh_2) {
                chenh_lech = chenh_1;
                use = *tmp1;
                pick_2 = false;
            }
            else {
                chenh_lech = chenh_2;
                use = *tmp2;
            }
        }
        while(min(top_thua.second, use.second)) {
            int tmp = mp[top_thua.first].back();
            mp[top_thua.first].pop_back();
            a[tmp] += chenh_lech;
            top_thua.second--;
            use.second--;
            ans += chenh_lech;
        }
        if (pick_2) {
                thieu.erase(tmp2);
            }
        else thieu.erase(tmp1);
        if (use.second)
            thieu.insert(use);
        
    }
    cout << ans << "\n";
    print(a);
}

int main()
{
    IOS;
    solve();
}