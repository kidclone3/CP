// https://codeforces.com/problemset/problem/1365/A
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
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
void solve();
bool mexCalculation(unordered_set<int> &row, unordered_set<int> &col, int n, int m) {
    int mex_row, mex_col;
    mex_row = mex_col = 0;
    while (row.find(mex_row) != row.end())
    {
        mex_row++;
    }
    while (col.find(mex_col) != col.end())
    {
        mex_col++;
    }
    if (mex_row == n || mex_col == m) {
        return false;
    }
    else {
        row.insert(mex_row);
        col.insert(mex_col);
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    unordered_set<int> row, col;
    FOR(i, n) {
        FOR(j, m) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                row.insert(i);
                col.insert(j);
            }
        }
    } 
    bool init = 0; 
    // Vivek = 0, Ashish = 1;
    while(mexCalculation(row, col, n, m))
    {
        init = !init;
    }
    cout << (init ? "Ashish" : "Vivek") << "\n";
}