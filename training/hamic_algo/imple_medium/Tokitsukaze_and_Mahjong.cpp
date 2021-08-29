#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3][10] = {0}; // m, p, s
    for(int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        // '1' - '0'

        if (s[1] == 'm')    a[0][s[0]-'0'] ++;
        else if(s[1] == 'p')    a[1][s[0]-'0']++;
        else a[2][s[0]-'0']++;    
    }
    int result = 2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j < 8; j++)
        {
            int tmp = 3 - (a[i][j] > 0) - (a[i][j+1] > 0) - (a[i][j+2] > 0);
            result = min(result, tmp);
            // 1s 2s 3s
        }
        for (int j = 1; j < 10; j++)
        {
            cout << a[i][j] << " \n"[j==9];
            result = min(result, 3 - a[i][j]);
            // 
        }
    }
    cout << result;

}