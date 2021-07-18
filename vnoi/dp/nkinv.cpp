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

ll f[60000+5];
void solve(){
    int n;
    cin >> n;
    ll ans = 0LL;
    while(n--) {
        int x; cin >> x;
        // Đây là lần đầu tiên mình thấy có người code fenwick tree xịn xò như này.
        // Tại sao lại phải x+1???
        // Vì chúng ta chỉ lấy tất cả các giá trị lớn hơn mình (quy luật của dãy nghịch thế)
        for (int i = x+1; i <= 60000; i+= i & -i) ans+= f[i];
        // Còn ở đây thì sao? Chúng ta cộng 1 vào dãy [1, x].
        for (int i = x; i; i -= i&-i) f[i]+= 1LL;
    }
    cout << ans;
}

int main()
{
    IOS;
    solve();
}