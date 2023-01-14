#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
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
};
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
const int N = 4;
vector<string> grid;
void solve();
vi ans;
bool inside(int x, int y) {
    return 0 <=x && x < N && 0 <= y && y < N;
}
void change(vi rows, vi cols, vector<string> a) {
    
    EACH(i, rows) {
        EACH(j, cols) {
            if (a[i][j] == 's') a[i][j] = 'n';
            else a[i][j] = 's';
            FOR(z, 4) {
                int x = i+dx[z];
                int y = j+dy[z];
                if (inside(x, y)){
                    if (a[x][y] == 's') a[x][y] = 'n';
                    else a[x][y] = 's';
                }
                
            }   
        }
    }
    int cnt = 0;
    EACH(it, a) {
        cnt += count(all(it), 's');
    }
    if (cnt == N*N || cnt == 0) {
        ans.push_back((int) rows.size() * cols.size()); 
    }
}
int main()
{
    IOS;
    solve();
}
void solve() {
    grid.resize(N);  
    int tmp = 0; 
    FOR(N) {
        cin >> grid[i];
        tmp += count(all(grid[i]), 's');
    }
    if (tmp == N*N || tmp == 0) {
        cout << 0;
        return;
    }
    for(int i = 1; i < (1<<N); ++i) {
        for(int j = 1; j < (1<<N); ++j) {
            vi rows, cols;
            for(int z = 0; (1<<z) <= i; ++z) {
                if ((1<<z) & i) rows.pb(z);
            }
            for(int z = 0; (1<<z) <= j; ++z) {
                if ((1<<z) & j) cols.pb(z);
            }
            change(rows, cols, grid);
        }
    }
    if (ans.empty()) {
        cout << "-1";
    }
    else {
        cout << ans.size() << "\n";

    }
}
