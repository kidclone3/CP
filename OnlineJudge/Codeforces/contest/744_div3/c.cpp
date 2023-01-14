#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
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
        cout << it << " ";
    }
    cout << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<string> vt(n);
    FOR(n) cin >> vt[i];
    bool found = false;
    int num = 0;
    FOR(i, n-1, -1, -1) FOR(j, m-1, -1, -1) {
        if (vt[i][j] == '*') {
            int cnt = 0;
            FOR(h, 1, max(n, m)+1) {
                if (i-h < 0 || j + h >= m || j - h < 0) break;
                if ((vt[i-h][j+h] == '*' || vt[i-h][j+h] == '?') && (vt[i-h][j-h] == '*' || vt[i-h][j-h] == '?')) {
                    vt[i-h][j+h] = vt[i-h][j-h] = '?';
                    cnt++;
                }
                else break;
            }
            if (cnt == 0) continue;
            else if (cnt < d) {
                cout << "NO\n";
                return;
            }
            else num++;

        }
    }
    cout << (num ? "YES\n" : "NO\n");
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}