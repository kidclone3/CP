#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t; cin >> t;
    while(t--) {
        int s, n; cin >> s >> n;
        for (int i = 1; i < n; i++)
        {
            int tmp = pow(10, (int) log10(s - n + i));
            cout << tmp << " ";
            s -= tmp;
        }
        cout << s << "\n";
    }
}