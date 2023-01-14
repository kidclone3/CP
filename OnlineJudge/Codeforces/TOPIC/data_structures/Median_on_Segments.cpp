// https://codeforces.com/problemset/problem/1005/E1
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
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
struct Median{
    multiset<ll> left, right;
    size_t size;
    Median() {

    }
    void add(ll x) {
        if (!right.empty() && x >= *right.begin()) {
            right.insert(x);
        }
        else left.insert(x);
        balance();
    }
    void balance() {
        size = left.size() + right.size();
            while(left.size() < size / 2) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            while(right.size() < (size + 1) / 2) {
                right.insert(*left.rbegin());
                left.erase(--left.end());
            }
    }
    ll mid() {
        size = left.size() + right.size();
        if (size & 1) return *right.begin();
        return *left.rbegin();
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    int pos;
    FOR(n) {
        cin >> a[i];
        if (a[i] == m) pos = i;
    }
    Median median;
    ll ans = 0;
    int i = pos-1, j = pos;
    while(i >= 0 && j < n) {
        median.add(a[j++]);
        if (median.mid() == (ll) m) ans++;
        if (j >= n) break;
        median.add(a[j++]);
        if (median.mid() == (ll) m) ans++; 
        median.add(a[i--]);
        if (median.mid() == (ll) m) ans++;
    }
    cout << ans;
}

int main()
{
    IOS;
    solve();
}