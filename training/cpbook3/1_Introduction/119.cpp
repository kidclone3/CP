#include<bits/stdc++.h>
using namespace std;
int main() {
    int t = 0;
    int n;
    while(cin >> n) {
        if (t) cout << "\n";
        string s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            string name;
            int money, numbers;
            cin >> name >> money >> numbers;
            if (numbers)
                mp[name] -= money / numbers * numbers;
            for(int j = 0; j < numbers; ++j) {
                string fr; cin >> fr;
                mp[fr] += money/numbers;
            }
        }
        for(auto it : s) {
            cout << it << " " << mp[it] << "\n";
        }
        t++;
    }
}