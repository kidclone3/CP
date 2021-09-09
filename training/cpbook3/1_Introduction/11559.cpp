#include<bits/stdc++.h>
using namespace std;
int n, b, h, w;
const int inf = 1e9;
int main() {
    while(cin >> n >> b >> h >> w) {
        int mn = inf;
        int price;
        
        for (int i = 0; i < h; i++)
        {
            int mx_slot = 0;
            cin >> price;
            for (int j = 0; j < w; j++)
            {
                int tmp; cin >> tmp;
                mx_slot = max(tmp, mx_slot);
            }
            if (mx_slot > n) {
                mn = min(mn, n*price);
            }
        }
        if (mn > b) cout << "stay home\n";
        else cout << mn << "\n";
    }
}