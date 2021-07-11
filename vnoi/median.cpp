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
    Median(size_t sz) {
        size = sz;
    }
    void add(ll x) {
        if (!right.empty() && x >= *right.begin()) {
            right.insert(x);
        }
        else left.insert(x);
        balance();
    }
    void balance() {
        if (left.size() + right.size() == size) {
            while(left.size() < size / 2) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            while(right.size() < (size + 1) / 2) {
                right.insert(*left.rbegin());
                left.erase(--left.end());
            }
        }
    }
    void remove(ll x) {
        auto it1 = left.lower_bound(x);
        auto it2 = right.lower_bound(x);
        if (*it1 == x) {
            left.erase(it1);
        }
        else {
            right.erase(it2);
        }
        balance();
    }
    ll mid() {
        if (left.size() + right.size() < size) return 0LL;
        if (size & 1) return *right.begin();
        return *left.rbegin();
    }
};
ll solve();
int main()
{
    IOS;
    int t;
    cin >> t;
    FOR(t) cout << "Case #" << i+1 <<": " << solve() << "\n";
}
ll solve() {
    const ll MOD = 65536;
    ll seed, mul, add, n, k;
    cin >> seed >> mul >> add >> n >> k;
    Median median(k);
    vector<ll> a(n);
    a[0] = seed;
    median.add(a[0]);
    ll sum = 0LL;
    FOR(i, 1, n) {
        a[i] = (a[i-1] * mul % MOD + add) % MOD;
        median.add(a[i]);
        if (i >= k) {
            median.remove(a[i-k]);
        }
        sum += (ll) median.mid();
    }
    return sum;
}
