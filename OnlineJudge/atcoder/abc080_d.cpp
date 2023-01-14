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

const int N = 2e5+5;
int tt[N], s[N/2], t[N/2], c[N/2], sm[N];

void solve(){
    // Ý tưởng: dùng tổng tích lũy để đếm xem trong 1 khoảng tg cần bao nhiêu máy.
    int n, C; cin >> n >> C;
    FOR(n) {
        cin >> s[i] >> t[i] >> c[i];
    }
    FOR(i, 1, C+1) {
        // Tinh xem voi moi may C thi se can dung bao nhieu tg.
        fill(tt, tt+N, 0);
        FOR(j, n) {
            if (c[j] == i) {
                tt[2*s[j]-1]++;
                tt[2*t[j]]--;
            }
        }
        FOR(j, 1, N) tt[j] += tt[j-1];
        FOR(j, 0, N) if (tt[j] > 0) sm[j]++;
    }
    int mx = *max_element(sm, sm+N);
    cout << mx;
}

int main()
{
    IOS;
    solve();
}