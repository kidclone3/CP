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
        cout << it << "\n";
    }
    cout << "\n";
};
int N;
string s("");
vector<string> ans;
void out() {
    int sum = 0;
    int cnt = count(all(s), '(');
    if (cnt != (int) s.size() / 2) return;
    EACH(it, s) {
        if (sum < 0) return;
        if (it == '(') sum++;
        else sum--;
    }
    if (sum == 0) ans.push_back(s);
}
void backtrack(int n) {
    if (n == 2 * N) {
        out();
    }
    else {
        for(char i = '('; i <= ')'; ++i) {
            s.push_back(i);
            backtrack(n+1);
            s.pop_back();
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
    cin >> N;   
    backtrack(0);
    cout << ans.size() << "\n";
    print(ans);
}
