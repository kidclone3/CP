#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int solve() {
    int n; cin >> n;
    int a[n];
    int pos_1 = -1;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) pos_1 = i;
    }
    // Da co vi tri cua so 1, gio lam j tiep?
    // Bat dau tu so 1, chuyen sang 2 ben.
    // Dung 2 con tro, de add ben trai va ben phai.
    string ans(n, '0');
    ans[0] = '1';
    int left, right;
    left = pos_1-1;
    right = pos_1+1;
    set<int> st;
    st.insert(1);
    int i = 2;
    while(i <= n) {
        if (right == n || a[left] < a[right]) st.insert(a[left--]);
        else st.insert(a[right++]);
        if ((int) st.size() == i && *prev(st.end()) == i) {
            ans[i-1] = '1';
        }
        i++;
        // for(auto it : st) cout << it << " ";
        // cout << "\n";
    }
    cout << ans <<"\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
