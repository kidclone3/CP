#include <bits/stdc++.h>
using namespace std;

int dequy(string ss, char c) {
    if (ss.size() == 1) {
        return !(ss[0] == c);
    } 
    // Neu chon nua ben trai toan la chu c, nua phai la xau c+1-good, nhu nao?
    int nn = ss.size()/2;
    string s1 = ss.substr(0, nn);
    string s2 = ss.substr(nn, nn);
    int left = nn - count(s1.begin(), s1.end(), c) + dequy(s2, c+1);
    int right = nn - count(s2.begin(), s2.end(), c) + dequy(s1, c+1);

    return min(left, right);
}

void solve() {
    int n; 
    string s; 
    cin >> n;
    cin >> s;
    cout << dequy(s, 'a') <<"\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}