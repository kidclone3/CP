#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve() {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    string s;
    cin >> s;
    F_OR(i, 0, n/2, 1) {
        if (s[i] == '0' || s[n-i-1] == '0') {
            if (s[i] == '1' || s[n-i-1] == '1') {
                cout << "-1\n";
                return;
            }
            else {
                s[i] = s[n-i-1] = '0';
                a-=2;
            }
        }
        else if (s[i] == '1' || s[n-i-1] == '1') {
            s[i] = s[n-i-1] = '1';
            b-=2;
        }
    }
    if (n&1) {
        if (s[n/2] == '0') a--;
        else if (s[n/2] == '1') b--;
        else {
            if (a&1) {
                s[n/2] = '0';
                a--;
            } 
            else {
                s[n/2] = '1';
                b--;
            }
        }
    }
    // ok, chi con lai th cac cap. ? ?
    F_OR(i, 0, n/2, 1) {
        int j = n - i - 1;
        if (s[i] == '?') {
            if (a>=2) {
                s[i] = s[j] = '0';
                a-=2;
            }
            else {
                s[i] = s[j] = '1';
                b-=2;
            }
        }
    }
    if (a != 0 || b != 0) {
        cout<<"-1\n";
        return;
    }
    cout<<s<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input1.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
