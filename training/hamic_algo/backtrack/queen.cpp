#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << "\n";
    }
    cout << "\n";
};
void solve();
const int N = 8;
vector<string> grid(N, string(N, '0'));
bool check(int x, int y) {
    int dx[] = {0, -1, 1};
    int dy[] = {-1, -1, -1};
    auto inside = [&] (int i, int j) {
        return 0 <= i && i < N && 0 <= j && j < N;
    };
    FOR(z, 3) {
        int i = x, j = y;
        while(inside(i, j)) {
            if (grid[i][j] == '1') return false;
            i += dx[z];
            j += dy[z];
        }
    }
    return true;
}
vector<vector<string>> ans;
void out(){
    ans.push_back(grid);
}
void backtrack(int k) {
    if (k == N) {
        out();
    }
    else {
        FOR(i, N) {
            // We will put the queen from left to right, up to bottom.
            if (grid[i][k] == '0') {
                if (check(i, k)) {
                    grid[i][k] = '1';
                    backtrack(k+1);
                    grid[i][k] = '0';
                }
            }
        }
    }
}

int main()
{
    IOS;
    // Bài toán xếp 8 quân hậu nổi tiếng
    solve();
}
void solve() {
    backtrack(0);
    cout << ans.size() << '\n';
    EACH(it, ans) {
        print(it);
    }
}
