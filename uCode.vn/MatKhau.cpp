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
int MOD = 1000000000 + 7;
ll mod (ll ans) {
    while (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}
ll StringToInt(string a) {
    ll res =0;
    for (auto & it:a) {
        res*=10;
        res += it - '0';
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; 
    cin >> s;
    ll ans = 1;
    string temp = "";
    F_OR(i, 0, s.size(), 1) {
        if (s[i]>='0' && s[i] <='9') {
            temp+=s[i];
        }
        else {
            if (temp != "") {
                ans %= MOD;
                ans *= StringToInt(temp) % MOD;
                ans %= MOD;
                temp = "";
            }
        }
    }
    if (temp != "") {
        ans %= MOD;
        ans *= StringToInt(temp) % MOD;
        ans %= MOD;
    }
    cout << ans;
}