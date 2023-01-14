#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
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
const int N = 10;
int n, m; 
bool mp[N][N], check[N];
vi tmp = {1};
int ans = 0;
void out() {
    FOR(i, 1, n) {
        if (!mp[tmp[i-1]][tmp[i]]) return;
    }
    ans++;
}
void gen(int k) {
    if (k == n+1) {
        out();
        return;
    }
    else {
        FOR(i, 2, n+1) {
            if (!check[i]) {
                tmp.push_back(i);
                check[i] = true;
                gen(k+1);
                tmp.pop_back();
                check[i] = false;
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    check[0] = check[1] = 1;
    FOR(m) {
        int x, y; cin >> x >> y;
        mp[x][y] = mp[y][x] = 1;
    }
    gen(2);
    cout << ans;
}

int main()
{
    IOS;
    solve();
}