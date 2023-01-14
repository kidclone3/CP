// https://codeforces.com/problemset/problem/1175/B
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
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it.first << " " << it.second <<'\n';
    }
    cout << "\n";
};
void solve();
const ll INF = 1LL << 32LL;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
void solve() {
    int l;
    cin >> l;
    ll curr = 0;
    stack<ll> st;
    st.push(1);
    FOR(l) {
        string s;
        cin >> s;
        if (s == "for") {
            ll x;
            cin >> x;
            st.push(min(INF, st.top() * x));
        }
        else if (s == "end") {
            st.pop();
        }
        else {
            curr += st.top();
        }
    }
    if (curr >= INF) {
        cout << "OVERFLOW!!!";
    }
    else {
        cout << curr;
    }
}
