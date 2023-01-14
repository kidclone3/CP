#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
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
void swap_a(vector<int> &a, int k) {
    if (k==1) {
        F_OR(i, 0, a.size() -1, 2) {
            swap(a[i], a[i+1]);
        }
    }
    else {
        FOR(i, a.size()/2) {
            swap(a[i], a[i+a.size()/2]);
        }
    }
}
bool check(vector<int> a) {
    FOR(i, a.size()-1) { 
        if (a[i] >= a[i+1]) return false;
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(2*n), b1(2*n), b2(2*n);
    vector<bool> p1, p2;
    FOR(i, 2*n) {
        cin >> a[i];
    }
    if (check(a)) {
        cout << 0;
        return;
    }
    b1 = b2 = a;
    p1.pb(0); swap_a(b1, 0);
    while (b1[0] != 1)
    {
        p1.pb(!p1.back());
        if (p1.size() > 2*n) {
            break;
        }
        swap_a(b1, p1.back());
    }
    p2.pb(1); swap_a(b2, 1);
    while (b2[0] != 1)
    {
        p2.pb(!p2.back());
        if (p2.size() > 2*n) {
            break;
        }
        swap_a(b2, p2.back());
    }
    if (check(b1) && check(b2)) {
        cout << min (p1.size(), p2.size());
    }
    else if (check(b1)) {
            cout << p1.size();
            }
    else if (check(b2)) {
        cout<< p2.size();
    }
    else {
        cout << -1;
    }
        


}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
