#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
int mn = 1e9, mx = 0;
bool loop = false;
void recur(int i, vector<int> &a, vector<int> &b); 
void solve();
void out(vector<int> &a, vector<int> &b) {
    int tmp = 0;
    FOR(3) {
        tmp += min(a[i], b[(i+1) % 3]);
    }
    mn = min(mn, tmp);
}
int main()
{
    IOS;
    solve();
}
void recur(int i, vector<int> &a, vector<int> &b) {
    if (i == 3) {
        out(a, b);
    }
    else {
        int tmp1 = a[i], tmp2 = b[i];
        if (a[i] >= b[i]) {
            a[i] -= b[i];
            b[i] = 0;
        }
        else {
            b[i] -= a[i];
            a[i] = 0;
        }
        recur(i+1, a, b);
        a[i] = tmp1;
        b[i] = tmp2;
        tmp1 = a[i];
        tmp2 = b[(i + 2) % 3];
        if (a[i] >= tmp2) {
            a[i] -= tmp2;
            b[(i + 2) % 3] = 0;
        }
        else {
            b[(i + 2) % 3] -= a[i];
            a[i] = 0;
        }
        recur(i+1, a, b);
        a[i] = tmp1;
        b[(i + 2) % 3] = tmp2;

    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(6), b(6);
    FOR(3) {
        cin >> a[i]; 
        a[i+3] = a[i];
    }
    FOR(3) {
        cin >> b[i]; 
        b[i+3] = b[i];
    }
    mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    FOR(i, 3) {
        vector<int> aa, bb;
        FOR(j, i, i+3) {
            aa.pb(a[j]);
            bb.pb(b[j]);
        }
        recur(0, aa, bb);
    }
    cout << mn << " " << mx;

