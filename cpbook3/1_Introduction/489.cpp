#include <bits/stdc++.h>
using namespace std;
void solve() {
    string ans, inp;
    cin >> ans >> inp;
    map<char, bool> mp;
    set<char> st(ans.begin(), ans.end());
    int err = 0;
    
    for(auto &it : inp) {
        if (st.count(it)) {
            mp[it] = true;
            st.erase(it);
        }
        else if (!mp[it])
                {
                    mp[it] = true;
                    err++;
                }
        
        if (err >= 7) {
            cout << "You lose.\n";
            return;
        }
        if (st.empty()) break;
    }
    if (st.empty()) cout << "You win.\n";
    else cout << "You chickened out.\n";
}

int main() {
    int round;
    while(true) {
        cin >> round;
        if (round == -1) break;
        cout << "Round " << round << '\n';
        solve();
    }
}