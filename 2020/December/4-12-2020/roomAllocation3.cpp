#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<ll>
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

bool cmp1(tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b)
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
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.first < b.first;
}
ll partition(vi &room, vi &mark, ll left, ll right)
{
    ll pivot = room[right];
    ll pivot_i = mark[right];
    int i = left - 1; // i is smaller index;
    for (ll j = left; j <= right; j++)
    {
        // if current element is lower than pivot
        if (room[j] < pivot)
        {
            i++;
            swap(room[i], room[j]);
            // swap(mark[i], mark[j]);
        }
    }
    swap(room[i + 1], room[right]);
    // swap(mark[i + 1], mark[right]);
    return i + 1;
}
void qsort(vi &room, vi &mark, ll left, ll right)
{
    if (left > right)
        return;
    // pi = partition
    ll pi = partition(room, mark, left, right);
    qsort(room, mark, pi + 1, right);
    qsort(room, mark, left, pi - 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("room.inp", "r", stdin);
    // freopen("room.out", "w", stdout);
    ll n;
    vi out;
    vi room, mark;
    vector<tuple<ll, ll, ll>> inp;
    cin >> n;
    out.resize(n);
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        inp.pb({a, b, i});
    }
    sort(all(inp), cmp1);
    for (auto &i : inp)
    {
        auto it = lower_bound(all(room), get<0>(i));
        if (room.empty() || it == room.begin())
        {
            room.pb(get<1>(i));
            mark.pb(room.size());
            out[get<2>(i)] = room.size();
        }
        else
        {
            // neu chat tim thay phong trong==> thay gia tri cua phong trong do
            // vao, luu vi tri phong do vao mang out.
            --it;
            room[it - room.begin()] = get<1>(i);
            out[get<2>(i)] = mark[it - room.begin()];
        }
        qsort(room, mark, 0, room.size() - 1);
    }
    cout << room.size() << "\n";
    print(out);
}