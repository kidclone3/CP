#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
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
void solve();
int N, K;
vi tmp;
vector<vi> ans;
vb check;
void out() {
    ans.push_back(tmp);
}
void combination(int k, int start) {
    if (k == K) {
        out();
    }
    FOR(i, start, N) {
        if (!check[i]) {
            tmp.push_back(i+1);
            check[i] = 1;
            combination(k+1, i+1);
            check[i] = 0;
            tmp.pop_back();
        }
    }
}

int main()
{
    IOS;
    solve();
}
void solve() {
    // Liet ke to hop nCk.
    cin >> N >> K;
    check.resize(N);
    combination(0, 0);
    cout << ans.size() <<'\n';
    EACH(it, ans) print(it);
}
