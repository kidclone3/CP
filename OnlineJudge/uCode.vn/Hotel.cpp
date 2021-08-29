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
    int n;
    cin >> n;
    multiset<ll> room;
    vector<pair<ll, ll>> vt;
    F_OR(i, 0, n, 1) {
        ll s, e;
        cin >> s >> e;
        vt.pb({e,s});
    }
    sort(all(vt));
    EACH(x, vt) {
        ll s,e;
        e = x.first;
        s = x.second;
        auto it = room.lower_bound(s);
        if (*it == s) {
            room.erase(it);
            room.insert(e);
            continue;
        }
        if (it == room.begin()) {
                room.insert(e);
            }
            else {
                it--;
                room.erase(it);
                room.insert(e);
            }
    }
    cout << room.size();
}
