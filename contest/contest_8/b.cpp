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
string solve(string s) {
    if (s.size() < 4) return "NO\n";
    if (s=="2020") return "YES\n";
    int n = s.size() - 4;
        F_OR(i, 0, s.size() - n + 1, 1) {
            string ss = s;
            ss.erase(ss.begin() + i, ss.begin()+ i+n);
            if (ss == "2020") {
                return "YES\n";
            }
        }
    return "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // 2020 => size = 4.
        cout<<solve(s);
    }
}
