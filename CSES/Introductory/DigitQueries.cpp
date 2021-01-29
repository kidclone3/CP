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
   
    vector <ll> sz; // length of the string in i th digit
    sz.pb(0);
    ll sum = 0;
    F_OR(i, 1, 18, 1) {
        sum += (ll)9 * (ll) pow(10, i-1) * i;
        sz.pb(sum);
    }
    // print(sz);
    int q;
    cin >> q;
    for (int i = 0; i<q; ++i) {
        ll inp;
        cin >> inp;
        ll k = inp;
        int digit = lower_bound(all(sz), inp) - sz.begin();
        // cout<<digit<<'\n';
        if (digit==1) {
            cout<< inp <<"\n";
            continue;
        }
        k -= sz[digit-1];
        k++;
        ll temp = (ll) pow(10, digit-1) + k/digit - 1;
        string s = to_string(temp);
        cout<< s[k % digit] << '\n';

    }
}
