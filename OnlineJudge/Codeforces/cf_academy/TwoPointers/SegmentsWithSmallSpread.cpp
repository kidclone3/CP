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
int n;
ll a[N], k;
struct stack {
    vector<ll> s, s_min = {LLONG_MAX}, s_max = {LLONG_MIN};
    void push(ll x) {
        s.pb(x);
        s_min.pb(::min(s_min.back(), x));
        s_max.pb(::max(s_max.back(), x));
    }
    ll pop() {
        ll res = s.back();
        s.pop_back();
        s_min.pop_back();
        s_max.pop_back();
        return res;
    }
    bool empty() {
        return s.empty();
    }
    ll min() {
        return s_min.back();
    }
    ll max() {
        return s_max.back();
    }
};
::stack s1, s2;
void add(ll x) {
    s2.push(x);
}
void remove() {
    if (s1.empty()) {
        while(!s2.empty()) {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
bool good () {
    ll mn = min(s1.min(), s2.min());
    ll mx = max(s1.max(), s2.max());
    return (mx-mn) <=k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>> n>>k;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }
    int l = 0;
    ll res = 0;
    F_OR(r, 0, n, 1) {
        add(a[r]);
        while(!good()) {
            remove();
            l++;
        }
        res+= r-l+1;
    }
    cout<<res;
}
