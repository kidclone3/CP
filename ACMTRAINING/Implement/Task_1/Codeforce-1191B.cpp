#include<bits/stdc++.h>
using namespace std;
int solve() {
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    sort(s.begin(), s.end(), [&](string &a, string &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
            });
    if (s[0] == s[1] && s[1] == s[2]) {
        return 0;
    } else if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) return 1;
    
    if (s[0][1] == s[1][1] && s[1][1] == s[2][1]) {
        if (s[0][0]+1 == s[1][0] && s[1][0]+1 == s[2][0]) return 0;
        if (s[0][0]+1 == s[1][0] || s[0][0]+1 == s[2][0] || s[1][0]+1 == s[2][0]) return 1;
    }
    // TH3 : Chi co 2 trong 3 cai cung chat.
    if (s[0][1] == s[1][1] && s[1][0] - s[0][0] <= 2) return 1;
    if (s[1][1] == s[2][1] && s[2][0] - s[1][0] <= 2) return 1;
    if (s[0][1] == s[2][1] && s[2][0] - s[0][0] <= 2) return 1;
    return 2;
}
int main() {
    cout << solve();
    return 0;
}
