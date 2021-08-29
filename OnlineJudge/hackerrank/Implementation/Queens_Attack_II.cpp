#include <bits/stdc++.h>
using namespace std;
vector<int> d_row = {0, 0, -1, 1, 1, -1, -1, 1};
vector<int> d_col = {1, -1, 0, 0, 1, -1, 1, -1};
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int ans = 0;
    map<pair<int, int>, bool> mp;
    for (auto it : obstacles) {
        mp[{it[0], it[1]}] = true;
    }
    mp[{r_q, c_q}] = true;
    // xet hang ngang + doc.
    for (int j = 0; j < 8; ++j) {
        int l, r;
        l = r_q, r = c_q;
        l += d_row[j];
        r += d_col[j];
        while (1 <= l && l <= n && 1 <= r && r <= n)
        {
            if (mp[{l, r}]) {
                break;
            }
            else {
                ans++;
                // cout << l << " " << r << '\n';
            }
            l += d_row[j];
            r += d_col[j];
        }
        
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++)
    {
        vector<int> tmp(2);
        cin >> tmp[0] >> tmp[1];
        obstacles[i] = tmp;
    }
    cout << queensAttack(n, k, r, c, obstacles);
    
}