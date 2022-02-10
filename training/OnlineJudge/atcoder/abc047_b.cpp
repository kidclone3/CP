#include <bits/stdc++.h>
using namespace std;
int main() {
    int w, h, n;
    cin >> w >> h >> n;
    // w = ngang, h = doc.
    vector<vector<int>> a(h, vector<int>(w, 1));
    while(n--){
        int xi, yi, ai;
        cin >> xi >> yi >> ai;
        switch (ai)
        {
        case 1:
        // x = hang ngang, y = hang doc (truc toa do de-cac)
            for(int x = 0; x < xi; ++x) {
                for(int y = 0; y < h; ++y) {
                    a[y][x] = 0;
                }
            }
            break;
        case 2:
            for(int x = xi; x < w;++x) {
                for(int y = 0; y < h; ++y) {
                    a[y][x] = 0;
                }
            }
            break;
        case 3:
            for(int y = 0; y < yi; ++y) {
                for(int x = 0; x < w; ++x) {
                    a[y][x] = 0;
                }
            }
            break;
        case 4:
            for(int y = yi; y < h; ++y) {
                for(int x = 0; x < w; ++x) {
                    a[y][x] = 0;
                }
            }
            break;
        default:
            break;
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans += a[i][j];
        }    
    }
    cout << ans;
}