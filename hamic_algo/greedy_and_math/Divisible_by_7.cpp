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
void solve();
class Biginteger {
    public:
        string num;
        Biginteger(ll inp) {
            num = to_string(inp);
        }
        Biginteger(string inp) {
            num = inp;
        }
        string rev() {
            string s = num;
            reverse(all(s));
            return s;
        }
        void add() {
            int n = num.size();
            int tmp = 0;
            string ans = "";
            string s2 = rev(); 
            for(int i = n-1; i >= 0; --i) {
                int d1 = num[i] - '0';
                int d2 = s2[i] - '0';
                int d3 = d1 + d2 + tmp;
                if (d3 >= 10) {
                    d3 %= 10;
                    tmp = 1;
                }
                else tmp = 0;
                num[i] = (d3 + '0');
            }
            if (tmp == 1) {
                num = "1" + num;
            }
        }
        bool divisible_7() {
            ll ans = 0;
            int n = num.size();
            FOR(i, n) {
                ans *= 3;
                ans += num[i] - '0';
            }
            return ans % 7 == 0;
        } 
};
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t--) solve();
}
void solve() {
    string a;
    cin >> a;
    Biginteger num(a);
    FOR(i, 1000) {
        if (num.divisible_7()) {
            cout << num.num << "\n";
            return;
        }
        num.add();
    }
    cout << "-1\n";
}
