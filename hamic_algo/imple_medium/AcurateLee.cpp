#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int left = 0, right = n-1;
    for (; left < n && s[left] == '0'; ++left); // => so' 1 dau tien, hoac ko
    for (; right > -1 && s[right] == '1'; --right); // => so' 0 dau tien, hoac ko.

    if (left > right) {
        cout << s <<'\n';
        return;
    }
    cout << s.substr(0, left) + s.substr(right, n-right) << '\n';
}