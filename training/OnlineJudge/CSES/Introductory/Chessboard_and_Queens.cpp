#include <bits/stdc++.h>
using namespace std;
const int N = 10;
vector<string> board;
bitset<N> rw, ld, rd;
// rw = rows, ld = left diagonals, rd = right diagonals;
long long ans = 0LL;
void backtrack(int c) {
    if (c==8){
        ans++;
        return;
    }
    for (int r = 0; r < 8; ++r) {
        if (board[r][c] == '.' && !rw[r] && !ld[r-c+8-1] && !rd[r+c]) {
            rw[r] = ld[r-c+7] = rd[r+c] = true;
            backtrack(c+1);
            rw[r] = ld[r-c+7] = rd[r+c] = false;
        }
    }
}
int main() {
    for (int i = 0; i < 8; i++)
    {
        string s; cin >> s;
        board.push_back(s);
    }
    backtrack(0);
    cout << ans;
}