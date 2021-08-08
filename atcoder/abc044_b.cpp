#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    map<char, int> mp;
    for(auto it : s) {
        mp[it]++;
    }
    for (auto it : mp) {
        // cout << it.first << " " << it.second << "\n";
        if (it.second&1) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}