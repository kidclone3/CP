#include<bits/stdc++.h>
using namespace std;

#define ll long long

bitset<10> col;
bitset<30> majorDia, minorDia;

int grid[10][10];
int a[10][10];
int ans = 0;
void check() {
    int sum = 0;
    for(int i = 0; i < 8; ++i) 
        for(int j = 0; j < 8; ++j) {
            cerr << grid[i][j] <<" \n"[j == 7];
            if (grid[i][j] == 1) {
                sum += a[i][j];
            }
        }
    cerr <<'\n';
    ans = max(ans, sum);
}

void backtrack(int i) {
    // duyet theo cot.
    if (i == 8) {
        check();
        return;
    }
    for(int j = 0; j < 8; ++j) {
        if (!col[j] && !majorDia[i+j] && !minorDia[i-j+8]) {
            col[j] = majorDia[i+1] = minorDia[i-j+8] = grid[i][j] = 1;
            backtrack(i+1);
            col[j] = majorDia[i+1] = minorDia[i-j+8] = grid[i][j] = 0;
        }
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    for(int i = 0; i < 8; ++i) 
        for(int j = 0; j < 8; ++j) 
            cin >> a[i][j];
    backtrack(0);
    cout << ans;
    return 0;
}