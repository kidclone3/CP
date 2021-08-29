// https://codeforces.com/contest/1512/problem/E
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
int low(int k) {
    return k * (k+1) / 2;
}
int high(int n, int k) {
    return k * (2 * n + 1 - k) / 2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s; 
    vector<bool> a(n+1, 0);
    int k = r - l + 1;
    int i = n;
    if (s < low(k) || s > high(n, k)) {
        cout << "-1\n";
        return;
    }
    while (k>0 && i > 0) {
        if (low(k-1) <= s-i && s <= high(i, k)) {
            s-=i;
            a[i] = 1;
            k--;
        }
        i--;
    }
    vector<int> ans(n);
    int j = 1;
    FOR(i, l-1) {
        while(a[j]) j++;
        ans[i] = j++;
    }
    F_OR(i, r, n, 1) {
        while (a[j]) j++;
        ans[i] = j++;
    }
    j = 1;
    F_OR(i, l-1, r, 1) {
        while(!a[j]) j++;
        ans[i] = j++; 
    }
    print(ans);
}