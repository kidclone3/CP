#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int sum = (int) 'R' + 'B' + 'L';
    string ans = "";
    for(int i = 0; i < s.size(); ++i) {
        if (i+2 < s.size()) {
            if ((int) s[i] + s[i+1] + s[i+2] == sum) {
                ans += "C";
                i += 2;
            } else {
                if (s[i] == 'R') ans += "S";
                else if (s[i] == 'B') ans += "K";
                else if (s[i] == 'L') ans += "H";
            }
        } else {
                if (s[i] == 'R') ans += "S";
                else if (s[i] == 'B') ans += "K";
                else if (s[i] == 'L') ans += "H";
        }
    }
    cout << ans;
}
