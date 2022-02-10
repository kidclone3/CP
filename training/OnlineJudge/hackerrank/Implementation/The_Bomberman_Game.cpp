#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

vector<string> explode(vector<string> state) {
    int r = state.size();
    int c = state[0].size();
    auto inside = [&](int x, int y) {
        return 0 <= x && x < r && 0 <= y && y < c;
    };
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (state[i][j] == 'O') {
                for (int z = 0; z < 4; ++z) {
                    int x = i + dx[z];
                    int y = j + dy[z];
                    if (inside(x, y) && state[x][y] == '.') {
                        state[x][y] = 'x';
                    }
                }
                state[i][j] = 'x';
                // Danh dau x la nhung o se no.
            }
        }
    }
    // Dat bom vao nhung vi tri trong
    for (int i =0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (state[i][j] == '.') {
                state[i][j] = 'O';
            }
        }
    }
    // Nhung vi tri duoc danh dau no? => No?
    for (int i =0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (state[i][j] == 'x') {
                state[i][j] = '.';
            }
        }
    }
    return state;
}

vector<string> bomberMan(int n, vector<string> grid) {
    if (n == 1) {
        return grid;
    }
    int r = grid.size();
    int c = grid[0].size();
    vector<string> state2(r, string(c, 'O')), state3, state5;
    state3 = explode(grid);
    state5 = explode(state3);
    if (n % 2 == 0) {
        return state2;
    }
    else {
        if ((n - 3) % 4 == 0) {
            return state3;
        }
        else return state5;
    }
}

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    vector<string> a(n);
    for (int i = 0; i < r; i++)
    {
        cin >> a[i];
    }
    vector<string> ans = bomberMan(n, a);
    for (auto &it : ans) {
        cout << it << "\n";
    } 
}