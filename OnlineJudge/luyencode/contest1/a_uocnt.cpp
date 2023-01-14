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

vector<ll> test = {2, 13, 23, 1662803}; // Vi` n < 4*1e9.
pair<ll, ll> factor(ll n) {
    ll s = 0;
    while ((n & 1) == 0) {
        s++;
        n >>= 1;
    }
    return {s, n};
}
ll pow(ll a, ll d, ll n) {
    ll result = 1;
    a = a % n;
    while (d > 0) {
        if (d & 1) result = result * a % n;
        d >>= 1;
        a = a * a % n;
    }
    return result;
}
// Trả về false nếu n không phải là số nguyên tố.
bool test_a(ll s, ll d, ll n, ll a) {
    if (n == a) return true;
    ll p = pow(a, d, n);
    if (p == 1) return true;
    for (; s > 0; s--) {
        if (p == n-1) return true;
        p = p * p % n;
    }
    return false;
}
// Trả về true nếu n là số nguyên tố,
// false nếu n là hợp số.
bool miller(ll n) {
    if (n < 2) return false;
    if ((n & 1) == 0) return n == 2;
    ll s, d;
    tie(s, d) = factor(n-1);
    int ans = 1;
    EACH(it, test) {
        ans &= test_a(s, d, n, it);
    }
    // return test_a(s, d, n, 2) && test_a(s, d, n, 3) && test_a(s, d, n, 61);
    return ans;
}

void solve(){
    ll a; cin >> a;
    if (miller(a)) {
        cout << a <<'\n';
        return;
    }
    ll mx = LLONG_MIN;
    for (ll i = 2LL; i*i <= a; ++i) {
        if (a % i == 0) {
            if (miller(i)) mx = max(mx, i);
            if (miller(a/i)) mx = max(mx, a/i);
        }
    }
    cout << mx << '\n';
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}