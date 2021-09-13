// https://codeforces.com/contest/1418/problem/B
#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), l(n), ans(n);
    vector<int> free;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
        if (l[i] == 0) free.push_back(a[i]);
    }
    sort(free.begin(), free.end());
    reverse(free.begin(), free.end());
    for(int i = n-1; i >= 0; --i) {
        if (l[i]) ans[i] = a[i];
        else {
            ans[i] = free.back();
            free.pop_back();
        }
    }
    for(auto &it : ans) cout << it << " ";
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}