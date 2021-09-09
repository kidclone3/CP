#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> mp;
    vector<int> pos(a, 1);
    vector<int> rolls(c);
    for (int i = 0; i < b; i++)
    {
        int l, r; cin >> l >> r;
        mp[l] = r;
    }
    for (int i = 0; i < c; i++)
    {
        cin >> rolls[i];
    }
    if (a == 0) return;
    for (int i = 0; i < c; i++)
    {
        pos[i%a] += rolls[i];
        if (pos[i%a] >= 100) {
            pos[i%a] = 100;
            break; 
        }
        if (!mp.empty() && mp.count(pos[i%a])) pos[i%a] = mp[pos[i%a]];
        if (pos[i%a] >= 100) {
            pos[i%a] = 100;
            break; 
        }
    }
    for (int i = 0; i < a; i++)
    {
        cout << "Position of player " << i+1 <<" is "<<pos[i] << ".\n";
    }
    
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
