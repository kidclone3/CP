#include<bits/stdc++.h>
using namespace std;

int twoPluses(vector<string> grid) {
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();

    auto inside1 = [&] (int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 'G';
    };
    auto inside2 = [&] (int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 'g';
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int r = 0;
            // Ban kinh
            if (grid[i][j] == 'B') continue;
            while (inside1(i+r, j) && inside1(i, j+r) && inside1(i-r, j) && inside1(i, j-r)) {
                grid[i+r][j] = grid[i][j+r] = grid[i-r][j] = grid[i][j-r] = 'g';
                for (int x = 0; x < n; ++x) {
                    for(int y = 0; y < n; ++y) {
                        if (grid[x][y] == 'B') continue;
                        int R = 0;
                        while(inside1(x+R, y) && inside1(x,y+R) && inside1(x-R,y) && inside1(x,y-R)) {
                            ans = max(ans, (1 + 4*r) * (1 + 4*R));
                            R++;
                        }
                    }
                }
                r++;
            }
            r = 0;
            while (inside2(i+r, j) && inside2(i, j+r) && inside2(i-r, j) && inside2(i, j-r)) {
                grid[i+r][j] = grid[i][j+r] = grid[i-r][j] = grid[i][j-r] = 'G';
                r++;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << twoPluses(a);
}