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
    int n = 6;
    vi res(6, 0);
    vi tmp = {4, 8, 15, 16, 23, 42};
    map<int, vii> mp;
    FOR(i, n) FOR(j, n) {
        if (i != j)
            mp[tmp[i] * tmp[j]].push_back({tmp[i], tmp[j]});
    }
    // EACH(it, mp) cout << it.first << " ";
    vi a(6);
    printf("? 1 6\n");
    fflush(stdout);
    int l1, r1, ans;
    scanf("%d", &ans);
    tie(l1, r1) = mp[ans].back();
    printf("? 1 5\n"); fflush(stdout);
    scanf("%d", &ans);
    EACH(it, mp[ans]) {
        if (it.first == l1) {
            res[0] = l1;
            res[5] = r1;
            res[4] = it.second;
            break;
        }
        else if (it.second == l1) {
            res[0] = l1;
            res[5] = r1;
            res[4] = it.first;
            break;
        }
        else if (it.first == r1) {
            res[0] = r1;
            res[5] = l1;
            res[4] = it.second;
            break;
        }
        else if (it.second == r1) {
            res[0] = r1;
            res[5] = l1;
            res[4] = it.first;
            break;
        }
    }
    printf("? 2 3\n"); fflush(stdout);
    scanf("%d", &ans);
    tie(l1, r1) = mp[ans].back();
    printf("? 2 4\n"); fflush(stdout);
    scanf("%d", &ans);
    EACH(it, mp[ans]) {
        if (it.first == l1) {
            res[1] = l1;
            res[2] = r1;
            res[3] = it.second;
            break;
        }
        else if (it.second == l1) {
            res[1] = l1;
            res[2] = r1;
            res[3] = it.first;
            break;
        }
        else if (it.first == r1) {
            res[1] = r1;
            res[2] = l1;
            res[3] = it.second;
            break;
        }
        else if (it.second == r1) {
            res[1] = r1;
            res[2] = l1;
            res[3] = it.first;
            break;
        }
    }
    printf("! ");
    EACH(it, res) printf("%d ", it);
    printf("\n");
    fflush(stdout);
}

int main()
{
    // IOS;
    solve();
}