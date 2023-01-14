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
const int N = 505;
char a[N][N];
void solve();
void print(char (&a)[N][N], int c, int r) {
    F0R(i, 1, c+1) {
        F0R(j, 1, r+1) {
            cout << a[i][j];
        }
        cout <<'\n';
    }
}
void update (char (&a)[N][N], int i, int j) {
    if (a[i][j] == '.') {
        a[i][j] = 'D';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}
void solve() {
    int c, r;
    cin >> c >> r;
    int w = 0;
    vector<pair<int, int>> wolf;
    F0R(i, 1, c+1) {
        F0R(j, 1, r+1) {
            cin >> a[i][j];
            if (a[i][j] =='W') wolf.pb({i, j});
        }
    }    
    if (wolf.empty()) {
        cout <<"YES\n";
        print(a, c, r);
        return;
    }
    EACH(it, wolf) {
        if (a[it.first+1][it.second] == 'S') {
            cout << "NO";
            return;
        } 
        if (a[it.first-1][it.second] == 'S') {
            cout << "NO";
            return;
        }
        if (a[it.first][it.second+1] == 'S') {
            cout << "NO";
            return;
        } 
        if (a[it.first][it.second-1] == 'S') {
            cout << "NO";
            return;
        }
    }
    F0R(i, 1, c+1) {
        F0R(j, 1, r+1) {
            if (a[i][j] == 'S') {
                update(a, i+1, j);
                update(a, i-1, j);
                update(a, i, j+1);
                update(a, i, j-1);
            }
        }
    }
    cout <<"YES\n";
    print(a, c, r);
}