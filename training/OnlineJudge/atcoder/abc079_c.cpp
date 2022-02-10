#include<bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    vector<int> digit;
    for (int i = 0; i < 4; i++)
    {
        digit.push_back(s[i]-'0');
    }
    for(int i = 0; i < 8; ++i) {
        int ans = digit[0];
        for(int j = 0; j < 3; ++j) {
            if (i & (1<<j)) ans += digit[j+1];
            else ans -= digit[j+1];
        }
        if (ans == 7) {
            cout << digit[0];
            for(int j = 0; j < 3; ++j) {
                if (i & (1<<j)) cout << "+";
                else cout << "-";
                cout << digit[j+1];
            }
            cout << "=7";
            return 0;
        }   
    }
}