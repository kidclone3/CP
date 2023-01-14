#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void check(string s) {
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 'B' && s[i-1] == 'B') return;
    }
    ans.push_back(s);
}

int main() {
    int n;  cin >> n;
    for (int i = 1; i < (1<<n); ++i) {
        string s = "";
        for (int j = 0; j < n; ++j) {
            if (i & (1<<j)) s.push_back('A');
            else s.push_back('B');
        }
        check(s);        
    }
    sort(ans.begin(), ans.end());
    for (auto &it : ans) {
        cout << it << "\n";
    }
}