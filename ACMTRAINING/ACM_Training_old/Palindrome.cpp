#include <bits/stdc++.h>
using namespace std;

int main() {
    // char a = 'A';
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    string s;
    int dem[30];
    for (int i = 0; i < 30; ++i) {
        dem[i] = 0;
    }
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]]++;
    }
    string ans = "";
    bool le = false;
    char le_char;
    int le_dem;
    // map => {key, value}
    for (char i = 'A'; i <= 'Z'; ++i) {
        if (mp[i] % 2 == 1) {
            if (le == false) {
                le = true;
                le_char = i+'A';
                le_dem = mp[i];
            }
            else {
                cout << "NO SOLUTION";
                return 0;
            }
        }
    }
    // ans = B
    while(le == true && le_dem > 0) {
        ans += le_char;
        le_dem--;
    }
    // ans = BBB;
    dem[le_char - 'A'] = 0;
    for (int  i = 0; i <= 'Z'- 'A'; ++i) {
        if (dem[i] != 0) {
            // int tmp = dem[i];
            // while(tmp > 0) {
            //     // ans = i + 'A' + ans;
            //     char tmp2 = i + 'A';
            //     ans = tmp2 + ans + tmp2;
            //     tmp-=2;
            // }
            string tmp(dem[i]/2, i+'A');
            ans = tmp + ans + tmp;
        }
    }
    cout << ans;
}
