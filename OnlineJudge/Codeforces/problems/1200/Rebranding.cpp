// https://codeforces.com/contest/591/problem/B
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    vector<int> a[50];
    for(int i = 0; i < n; ++i) {
        a[s[i]esadsad - 'a'].push_back(i);
    }
    for(int i = 0; i < m; ++i) {
        char l, r;
        cin >> l >> r;
        swap(a[l-'a'], a[r-'a']);
    }
    string ans(n, ' ');
    for(int i = 0; i <= 'z' - 'a'; ++i) {
        for(auto &it2 : a[i]) {
            ans[it2] = i + 'a';
        }
    }
    cout << ans;
}