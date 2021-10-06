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

int n;
string s;
ii destination;
bool found = false;
void dfs(int i, ii position, ii direction) {
    if (found) return;
    if (i == n) {
        if (position == destination) {
            found = true;
        }
        return;
    }  
    if (s[i] == 'F') {
        position.first += direction.first;
        position.second += direction.second;
        dfs(i+1, position, direction);
    }
    else {
        ii direct1 = {direction.second, direction.first};
        ii direct2 = {-direction.second, -direction.first};
        dfs(i+1,position, direct1);
        dfs(i+1,position, direct2);
    }
}

void solve(){
    cin >> s;
    n = s.size();
    int x, y; cin >> x >> y;
    destination = {x, y};
    // (x, y): destination
    // (1, 0) xOy: Start
    // We will use DFS
    dfs(0, {0, 0}, {1, 0});
    cout << (found ? "Yes" : "No");
}

int main()
{
    IOS;
    solve();
}