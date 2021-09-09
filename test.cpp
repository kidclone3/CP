#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    // cin.ignore(32767, '\n');
    while (t--)
    {
        
        getline(cin, s);
        int i = 0;
        // Kiểm tra xem có dấu cách ở đầu dòng hay ko.
        for(; i < (int) s.size() && s[i] == ' '; ++i);
        if (i == s.size()) {
            cout << 0;
            continue;
        }
        // Kiểm tra xem có dấu cách ở cuối dòng hay ko.
        int n = s.size()-1;
        for(; n >= 0 && s[n] == ' '; --n);
        if (i == s.size() || n == -1) {
            cout << 0;
            continue;
        }
        int dem = 0;
        for (;i <= n; i++)
        {
            if (s[i] != ' ' && (s[i + 1] == ' ' || s[i+1] == '\t' || i == n))
                dem++;
        }
        cout << dem << "\n";
    }
}