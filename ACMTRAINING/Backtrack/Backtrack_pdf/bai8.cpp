#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;

bool grid[10][10];

vector<vector<string>> ans;

void out() {
    vector<string> tmp(n, string(n, '_'));
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) {
            if (grid[i][j]) tmp[i][j] = 'x';
        }
    ans.push_back(tmp);
}
void backtrack(int i, int x, int y) {
    if (i == n) {
        out();
        return;
    }
    if (x+1 >= n && y+1 >= n) return;
    if (x+1 < n) {
        grid[x+1][y] = 1;
        backtrack(i+1, x+1, y);
        grid[x+1][y] = 0;
    }
    if (y+1 < n) {
        grid[x][y+1] = 1;
        backtrack(i+1, x, y+1);
        grid[x][y+1] = 0;
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    cin >> n;
    grid[0][0] = 1;
    backtrack(1, 0, 0);
    for(int i = 0; i < (int) ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j)
            cout << ans[i][j] << '\n';
        cout << '\n';
    }
    return 0;
}