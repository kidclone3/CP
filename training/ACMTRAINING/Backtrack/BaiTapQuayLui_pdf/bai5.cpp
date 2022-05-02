#include <bits/stdc++.h>
using namespace std;
const int N = 9;
vector<vector<int>> a(N, vector<int>(N));

int rows[N], cols[N], areas[N];

int getBox(int row, int col) {
    return row/3*3 + col/3;
}

bool isOk(int i, int j, int number) {
    return !((rows[i] >> number) & 1) 
        && !((cols[j] >> number) & 1)
        && !((areas[getBox(i, j)] >> number) & 1);
}

void setInit() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            rows[i] |= 1 << a[i][j];
            cols[j] |= 1 << a[i][j];
            areas[getBox(i, j)] |= 1 << a[i][j];
        }
    }
}

vector<pair<int, int>> suspect;
bool found = false;

vector<vector<int>> ans(N, vector<int>(N));

void out() {
    ans = a;
}

void backtrack(int k) {
    if (found) return;
    if (k == (int) suspect.size()) {
        out();
        found = true;
        return;
    }
    int i, j;
    tie(i, j) = suspect[k];
    for(int nr = 1; nr <= N; ++nr) {
        if (isOk(i, j, nr)) {
            a[i][j] = nr;
            rows[i] |= 1 << nr;
            cols[j] |= 1 << nr;
            areas[getBox(i, j)] |= 1 << nr;
            backtrack(k+1);
            a[i][j] = 0;
            rows[i] &= ~(1 << nr);
            cols[j] &= ~(1 << nr);
            areas[getBox(i, j)] &= ~(1 << nr);
        }
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    // fixed size n = 9;

    // Using bitmask method to speed up check step.
    int n = N;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            // 0 ~ blank
            cin >> a[i][j]; 
            if (a[i][j] == 0) {
                suspect.push_back({i, j});
            }
        }
    }
    setInit();
    backtrack(0);
    if (found) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                cout << ans[i][j] << " \n"[j==N-1];
            }
        }
    } else cout << "not found!";
}
