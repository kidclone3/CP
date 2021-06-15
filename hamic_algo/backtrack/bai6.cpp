#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
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
// const int N = 1e9;
// bool check[N];
// vector<int> ans;
// int n;
// void sieve() {
//     int tmp = pow(10, n);
//     check[0] = check[1] = 1;
//     for(int i = 2; i*i <= tmp; ++i) {
//         if (check[i]) continue; 
//         for(int j = 2*i; j <= tmp; j+=i) {
//             check[j] = 1;
//         }
//     }
// }
// ll s = 0;
// Bài này nếu dùng sàng nguyên tố thông thường thì sẽ chết time ở n = 9. Vậy nên mình sẽ cài = miller rabin.
vector<int> test = {2, 3, 61}; // Vi` n < 4*1e9.
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
    return test_a(s, d, n, 2) && test_a(s, d, n, 3) && test_a(s, d, n, 61);
}
ll s = 0;
vector<ll> ans;
void out() {
    if (miller(s)) {
        ans.push_back(s);
    }
}
void backtrack(int k, int n) {
    if (k == n) {
        out();
    }
    else {
        FOR(i, 10) {
            s*=10;
            s+=i;
            if (miller(s))
                backtrack(k+1, n);
            s/=10;
        }
    }
}
void solve();
int main()
{
    IOS;
    solve();
}
void solve() {
    int n;
    cin >> n;   
    backtrack(0, n);
    cout << ans.size() << "\n";
    print(ans);
    // Tuy nhiên, giờ mình đã rút ra 1 kết luận: nếu n = 9 thì cũng chả có số siêu nguyên tố nào cả, nên tạch
}
