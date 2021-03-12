#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define ll long long

int primes[22] = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37, 41, 43, 47, 53, 59};
string s = "";
vector<ll> res;

void out(string s)
{
    ll tmp = 1;
    int c_one = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            tmp *= (ll)primes[i];
            c_one++;
        }
    }
    if (c_one >= 3)
        res.pb(tmp);
}
void gen(int n)
{
    if (n == 12)
    {
        out(s);
        return;
    }
    for (auto i = '0'; i < '2'; i++)
    {
        s += i;
        gen(n + 1);
        s.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    gen(0);
    sort(res.begin(), res.end());
    //for (auto it : res)
    //    cout << it << " ";
    //cout << "\n";
    cout << res.size() << "\n";
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << res[n - 1] << '\n';
    }
}