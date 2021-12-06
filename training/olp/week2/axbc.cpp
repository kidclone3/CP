#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve(){
    int a, b, c;
    cin >> a >> b >> c;

    if (c == 0) {
        return -1;
    } else {
        if (a == 0 && b == 0) return 0;
        if (a == 0 && b == 1) return -1;
        if (a == 0) return 0;
        int ans = 0;
        if ((b-1) % a == 0) ans++;
        if (c % 2 == 0 && (1+b) % a == 0) ans++;
        return ans;
    }
   
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        int ans = solve();
        cout << (ans == -1 ? "oo" : to_string(ans)) << "\n";
    }
}
