#include <bits/stdc++.h>
using namespace std;

int n, x_0, y_0;
int d8x[] = {1, 1, 2, 2, -1, -1, -2, -2};
int d8y[] = {2, -2, 1, -1, 2, -2, 1, -1};
bool visited[100][100];
vector<pair<int, int>> path, ans;
bool found = false;

void out() {
    // for(auto &it : path) 
    //     ans.push_back(it);
    ans = path;
}

void backtrack(int i, int j) { 
    if ((int) path.size() == n*n) {
        out();
        found = true;
        return;
    }
    if (found) return;
    for(int k = 0; k < 8; ++k) {
        int x = i+d8x[k];
        int y = j+d8y[k];
        if (0 <= x && x < n && 0 <= y && y < n) {
            if (!visited[x][y]) {
                path.push_back({x, y});
                visited[x][y] = 1;
                backtrack(x, y);
                visited[x][y] = 0;
                path.pop_back();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    cin >> n >> x_0 >> y_0;
    visited[x_0][y_0] = 1;
    path.push_back({x_0, y_0});
    backtrack(x_0, y_0);
    if (found) {
        vector<vector<int>> grid(n, vector<int>(n));
        cerr << ans.size() << "\n";
        for(int i = 0; i < (int) ans.size(); ++i) {
            grid[ans[i].first][ans[i].second] = i;
        }

        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
            cout << grid[i][j] << " \n"[j==n-1];
        }
    } else cout << "not found";
}
