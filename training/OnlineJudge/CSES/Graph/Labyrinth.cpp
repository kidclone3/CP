#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };
const int N = 1e3+5;

char a[N][N];
bool visited[N][N];
void solve();
bool isValid(int i, int j) {
    if (a[i][j] == '.' || a[i][j] == 'B') {
        return !visited[i][j];
    }
    return false;
}
void printPath(pair<int, int> it, pair<int, int> a_locate, map<pair<int, int>, pair<int, int>> path) {
    string s ="";
    while (it != a_locate)
    {
        auto before = path[it];
        if (before.first > it.first) {
            s+='U';
            it = before;
            continue;
        }
        if (before.first < it.first) {
            s+='D';
            it = before;
            continue;
        }
        if (before.second > it.second) {
            s+='L';
            it = before;
            continue;
        }
        if (before.second < it.second) {
            s+='R';
            it = before;
            continue;
        }
    }
    reverse(all(s));
    cout << s.size() <<"\n" << s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}

void solve() {
    int n, m;
    cin >> n >> m;
    pair<int, int> a_locate, b_locate; 
    F0R(i, 1, n+1) {
        F0R(j, 1, m+1) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                a_locate = {i, j};
            }
            if (a[i][j] == 'B') {
                b_locate = {i, j};
            }
        }

    map<pair<int, int>, pair<int, int>> path;
    visited[a_locate.first][a_locate.second] = true;
    queue<pair<int, int>> q;
    q.push(a_locate);
    while (!q.empty())
    {
        auto s = q.front();
        q.pop();
        FOR(i, 4) {
            int x = s.first + dCol[i];
            int y = s.second + dRow[i];
            if (isValid(x, y)) {
                visited[x][y] = true;
                path[{x, y}] = s;
                if( x == b_locate.first && y == b_locate.second) {
                    cout << "YES\n";
                    printPath(make_pair(x, y), a_locate, path);
                    return;
                } 
            q.push({x, y});
            }
        }
    }
    cout << "NO";
    

}