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

const int N = 2e4+5;
int a[N][15];
vi box_chat[15];
int box_count[15];
int staff_notif[N];

void solve(){
    int n, m, k; cin >> n >> m >> k;
    FOR(i, n) FOR(j, m) cin >> a[i][j];
    FOR(j, m) {
        FOR(i, n) {
            if (a[i][j]) box_chat[j].push_back(i);
        }
    }
    FOR(k) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        staff_notif[x]--;
        box_count[y]++;
    }
    FOR(i, m) {
        if (!box_chat[i].empty()) {
            EACH(it, box_chat[i]) {
                staff_notif[it] += box_count[i];
                // cout << it << " ";
            }
            // cout << "\n";Average Sleep Time
        }
    }
    // FOR(m) cout << box_count[i] << " ";
    // cout << "\n";
    FOR(n) cout << staff_notif[i] << " ";
}   

int main()
{
    IOS;
    solve();
}