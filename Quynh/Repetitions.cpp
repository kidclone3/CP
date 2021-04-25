#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int ans = 0;
    int dem = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) {
            dem++;
        }
        else {
            ans = max(ans, dem);
            dem = 1;
        }
    }
    cout << ans;
}