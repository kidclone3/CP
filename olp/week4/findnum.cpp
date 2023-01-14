#include<bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    while(s.size() > 1) {
        int ans = 0;
        for(auto it : s) ans += it-'0';
        s = to_string(ans);
    }
    cout << s;
}