#include <bits/stdc++.h>
using namespace std;

int n;
string s;
string a = "abacaba";

bool isEqual(string& b) {
    for (int i = 0; i < 7; ++i) {
        if (b[i] != a[i] && b[i] != '?')  return false;
    }
    return true;
}

string process(int idx) {
    string s1 = s.substr(0, idx);
    string s3 = s.substr(idx+7, n-(idx+7));
    for (int i = 0; i < (int) s1.size(); ++i) {
        if (s1[i] == '?') s1[i] = 'z';
    }
    for (int i = 0; i < (int) s3.size(); ++i) {
        if (s3[i] == '?') s3[i] = 'z';
    }
    string ss = s1 + a + s3;
    int cnt = 0;
    for (int i = 0; i < n - 6; ++i) {
        string b = ss.substr(i, 7);
        if (isEqual(b)) {
            cnt++;
        }
    } 
    if (cnt == 1) {
        return ss;
    }
    else return "-1";
}

void solve() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n - 6; ++i) {
        string b = s.substr(i, 7);
        if (isEqual(b)) {
            string ss = process(i);
            if (ss != "-1") {
                cout << "YES\n";
                cout << ss <<'\n';
                return;
            }
        }
    }
    cout << "NO\n";
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}