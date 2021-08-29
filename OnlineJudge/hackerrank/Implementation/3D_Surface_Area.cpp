#include <bits/stdc++.h>
using namespace std;

int surfaceArea(vector<vector<int>> A) {
    int ans = 0;
    int h = A.size();
    int w = A[0].size();
    for(int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 || i == h - 1) {
                ans +=A[i][j];
                if (h == 1) {
                    ans += A[i][j];
                }
            }
            if (A[i][j] != 0) ans += 2;
            if (j == 0 || j == w - 1) {
                ans += A[i][j];
                if (w == 1) {
                    ans += A[i][j];
                }
            }
            if (i != 0) {
                ans += abs(A[i][j] - A[i-1][j]);
            }
            if (j != 0) {
                ans += abs(A[i][j] - A[i][j-1]);
            }
        }
    }
    return ans;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int> (w, 0));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }   
    }
    // for (auto &it : a) {
    //     for (auto &it2 : it) {
    //         cout << it2 << " ";
    //     }
    //     cout << "\n";
    // }
    cout << surfaceArea(a);
}