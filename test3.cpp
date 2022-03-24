#include<bits/stdc++.h>
using namespace std;

int dx[] = {2,2,-2,-2, 1, -1, 1, -1};
int dy[] = {1,-1,1, -1, 2, 2, -2, -2};

int board[8][8];
bool ok = false;
int N = 8;
int cnt = 0;
void print() {
    for(int i=0; i<N; i++) {
        for(int j = 0; j < N; ++j) {
            cout << board[i][j] << " \n"[j==7];
        }
    }
}

int deg(int i, int j) {
    int ans = 0;
    for(int k=0; k<N; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (0 <= x && x < N && 0 <= y && y < N && !board[x][y])
            ans++;
    }
    return ans;
}

bool dfs(int mv, int i, int j) {
    board[i][j] = mv;
    if (mv == 64) return 1;
    vector<tuple<int, int, int>> vt;
    for(int k = 0; k < N; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (0 <= x && x < N && 0 <= y && y < N && !board[x][y]) {
            int d = deg(x, y);
            vt.push_back({d, x, y});
        }
    }
    sort(vt.begin(), vt.end());
    for(auto it : vt) { // Duyet qua cac bac tu thap den cao.
        int d, x, y;
        // cnt ++;
        // cout << cnt << "\n";
        tie(d, x, y) = it; // d = it[0], x = it[1], y = it[2];
        if (dfs(mv+1, x, y)) return 1;
    }
    board[i][j] = 0;
    return 0;
}

int main() {
    // memset(board, -1, sizeof board);

    int i, j;

    cin >> j >> i; 
    i--;
    j--;
    // board[i][j] = 1;
    dfs(1, i, j);
    print();
}
