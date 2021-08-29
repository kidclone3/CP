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
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    map<int, int> mp;
    set<int> st;

    F_OR(i, 0, n, 1) {
        int tmp;
        cin >> tmp;
        a[i] = {tmp, i};
        mp[tmp]++;
        st.insert(tmp);
    }
    // duyet set?
    sort(all(a));
    EACH(it, st) {
        if (mp[it] == 1) {
            auto j = lower_bound(all(a), make_pair(it, 0));
            cout<<j->second+1<<'\n';
            return;
        }
    }
    cout<<"-1\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
