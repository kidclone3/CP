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
const int N = 1e5+5;
ll a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<ll, int> mp;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
        mp[a[i]]++;
    }
    //sort(a, a+n);
    b[0] = mp.begin()->second;
    auto it = mp.begin();
    it++;
    F_OR(i, 1, mp.size(), 1) {
        b[i] = b[i-1] + it->second;
        it++;
    }
    // F_OR(i, 0, mp.size(), 1) {
    //     cout<<b[i]<<" ";
    // }
    ll M= b[mp.size()-1];
    if (M&1) {
        cout<<0;
        return 0;
    }
    int mid1, mid2;
    mid1 = lower_bound(b, b+mp.size(), M/2) - b;
    if (M/2 != b[mid1]) {
        cout<<0;
        return 0;
    }
    auto j = mp.begin();
    while(mid1--) {
        j++;
    }
    int f,s;
    f = j->first;
    j++;
    s = j->first;
    cout<<s-f;

}
