#include<bits/stdc++.h>
using namespace std;
int backtrack(char c, string &s) {
    // check how many char is need.
    if (s.size() == 1) return !(c == s[0]);
    int mn1 = s.size()/2 - count(s.begin(), s.begin() + s.size()/2, c);
    int mn2 = s.size()/2 - count(s.begin() + s.size()/2, s.end(), c);
    string s2 = s.substr(0,s.size()/2);
    string s1 = s.substr(s.size()/2, s.size()/2);
    return min(mn1+backtrack(c+1, s1), mn2 + backtrack(c+1, s2));
}
int solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    cout << backtrack('a', s) << "\n";
    return 0;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
