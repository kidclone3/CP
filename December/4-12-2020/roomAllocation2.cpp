#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
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

bool cmp1(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
    if (get<1>(a) == get<1>(b))
    {
        if (get<0>(a) == get<0>(b))
        {
            return get<2>(a) < get<2>(b);
        }
        else
            return get<0>(a) < get<0>(b);
    }
    return get<1>(a) < get<1>(b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("room1.inp", "r", stdin);
    freopen("room.out", "w", stdout);
    int n;
    vi out;
    vector<pair<int, int>> room;
    vector<tuple<int, int, int>> inp;
    cin >> n;
    out.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        inp.pb({a, b, i});
    }
    sort(all(inp), cmp1);
    // Se viet lai ham chat nhi phan
    for (auto &i : inp)
    {
        if (room.empty())
        {
            room.pb({get<1>(i), 1});
            continue;
        }
        // try new way of lower_bound;
        int first = get<0>(i);
        int second = get<1>(i);
        int third = get<2>(i);
        auto j = lower_bound(all(room), make_pair(first, -1));
        if (j == room.begin())
        {
            room.pb({second, room.size()});
            out[third] = room.size();
        }
        else
        {
            --j;
            room[j - room.begin()].first = second;
            out[third] = room[j - room.begin()].second;
        }
        for (auto &it : room)
            cout << it.first << " ";
        cout << "\n";
        sort(all(room));
    }
    cout << room.size() << "\n";
    print(out);
}