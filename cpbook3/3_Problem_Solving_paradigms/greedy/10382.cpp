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
int n, l, w;
bool cmp(pair<double, double> t1, pair<double, double> t2) {
    if (t1.first != t2.first) return t1.first < t2.first;
    else {
        return t1.second > t2.second;
    }
}
void solve(){
    vector<pii> sprinklers;
    vector<pair<double, double>> ranges;
    FOR(n) {
        int pos, r;
        scanf("%d%d", &pos, &r);
        sprinklers.push_back({pos, r});
        if (r >= (w*1.0/2)) {
            double dx = sqrt(r*r-(w*1.0/2)*(w*1.0/2));
            ranges.push_back({pos*1.0-dx, pos*1.0+dx});
        }
    }
    sort(all(ranges), cmp);
    double curr = 0.0;
    int ans = 0;
    FOR(i, n) {
        if (curr >= l) break;
        if (ranges[i].first > curr) {
            ans = -1;
            break;
        }
        while(i+1 < n && ranges[i+1].first <= curr) {
            i++;
        }
        ans ++;
        curr = ranges[i].second;
    }
    if (curr < l) ans = -1;
    // cout << "\n";
    // printPair(ranges);
    printf("%d\n", ans);
}

int main()
{
    // Still Wrong Answer
    IOS;
    while(scanf("%d%d%d", &n, &l, &w) != EOF) {
        solve();
    }
}