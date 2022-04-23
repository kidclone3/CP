#include <bits/stdc++.h>
using namespace std;

int n;
bool grid[20][20];
bitset<50> col, majorDia, minorDia;


void backtrack(int i) {
    if (i == n) {
        for(int x = 0; x < n; ++x) 
            for(int y = 0; y < n; ++y) {
                cout << grid[x][y] << " \n"[y == n-1];
            }
        cout << '\n';
        return;
    }
    for(int j = 0; j < n; ++j) {
        if (!col[j] && !majorDia[i+j] && !minorDia[i-j+n]) {
            grid[i][j] = 1;
            col[j] = majorDia[i+j] = minorDia[i-j+n] = 1;
            backtrack(i+1);

            grid[i][j] = 0;
            col[j] = majorDia[i+j] = minorDia[i-j+n] = 0;
        }
    }
}

int main() {
    cin >> n;
    backtrack(0);
}
