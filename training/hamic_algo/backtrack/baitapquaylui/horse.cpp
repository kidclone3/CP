#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define ll long long
#define pii pair<int, int>
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
        cout << it.first << " " << it.second << '\n';
    }
    cout << "\n";
};
int N;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
pair<int, int> operator+= (pair<int, int>& a, const pair<int, int>& b) {
    a.first += b.first;
    a.second += b.second;
    return a;
}
pair<int, int> operator-= (pair<int, int>& a, const pair<int, int>& b) {
    a.first -= b.first;
    a.second -= b.second;
    return a;
}
pair<int, int> operator+ (const pair<int, int>& a, const pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}
bool operator== (const pair<int, int>& a, const pair<int, int>& b) {
    return a.first == b.first && a.second == b.second;
}
vector<pair<int, int>> path, ans;
// vector<vector<pair<int, int>>> ans;
vector<vb> check;
void solve();
void out() {
    ans = path;
}
bool found = false;
bool inside(pii x) {
    return 0 <= x.first && x.first < N && 0 <= x.second && x.second < N;
}
void backtrack(pair<int, int> pos) {
    if (found) return;
    FOR(i, 8) {
        pii curr = pos+make_pair(dx[i], dy[i]);
        if (inside(curr)) {
            if (!check[curr.first][curr.second]) {
                check[curr.first][curr.second] = 1;
                path.push_back(curr);
                backtrack(curr);
                check[curr.first][curr.second] = 0;
                path.pop_back();
            }
            else if (curr == make_pair(0, 0) && path.size() == N*N) {
                out();
                found = true;
            }
        }
    }
}
int main()
{
    IOS;
    solve();
}
void solve() {
    cin >> N;    
    check.resize(N, vb(N, 0));
    check[0][0] = 1;
    path.push_back({0, 0});
    backtrack({0, 0});
    cout << ans.size() <<"\n";
    // print(ans);
    if (ans.size() != 0) {
        vector<vi> grid(N, vi(N));
        int i = 0;
        EACH(it, ans) {
            grid[it.first][it.second] = i++;
        }
        EACH(it, grid) {
            EACH(it2, it) {
                cout << it2 << " ";
            }
            cout << "\n";
        }
    }
}
