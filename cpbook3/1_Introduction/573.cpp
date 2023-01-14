#include<bits/stdc++.h>
using namespace std;
double h, u, d, f, height, fatigue_factor;
void solve() {
        height = 0.0;
        fatigue_factor = u * f / 100;
        int i = 1;
        bool success = true;
        while(true)
        {   
            height += u;
            if (u) u -= fatigue_factor;
            if (height > h) break;
            height -= d;
            if (height < 0) {success = false; break;}
            i++;
        }
        cout << (success ? "success on day " : "failure on day ") << i << "\n";
}
int main() {
    while(true) {
        cin >> h >> u >> d >> f;
        if (h==0) break;
        solve();
    }
}