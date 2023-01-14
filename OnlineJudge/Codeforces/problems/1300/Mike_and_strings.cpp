// https://codeforces.com/contest/798/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    // Co dinh 1 so, tim xem xoay bao nhieu lan.
    int mn = 1e9;
    string root = a[0];
    for(int i = 0; i < root.size(); ++i) {
        int ans = i;
        if (i) {
            char tmp = root[0];
            root.erase(root.begin());
            root.push_back(tmp);
        }
        for(int j = 1; j < n; ++j) {
            string tmp = a[j];
            int cnt = 0;
            while(tmp != root) {
                char tmp2 = tmp[0];
                tmp.erase(tmp.begin());
                tmp.push_back(tmp2);
                cnt++;
                if (cnt == tmp.size()) break;
            }
            if (cnt == tmp.size()) {
                cout << -1;
                return 0;
            }
            ans+=cnt;
        }
        mn = min(mn, ans);
    }
    cout << mn;
}