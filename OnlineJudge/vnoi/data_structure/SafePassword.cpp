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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int x;
    cin >> x;
    map<char, int> mp;
    for (char i = 'a'; i <= 'z'; ++i) {
        mp[i] = (x++)%26;
    }
    int ans = 0;
    EACH(it, s) {
        ans += mp[it];
    }
    vector<int> vt;
    cout<<ans;
}
