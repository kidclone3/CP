#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3,unroll-loops")

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int) (b) : i > (int) (b); i+=(s))
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

bool cmp(string a, string b) {
    if (a.size() != b.size()) return a.size() <= b.size();
    else {
        FOR(a.size()) {
            if (a[i] < b[i]) return true;
            else if(a[i] > b[i]) return false;
        }
    }
    return true;
}
string a, b;
int aa, bb;
int digSum(string x) {
    int ans = 0;
    EACH(it, x) ans += it-'0';
    return ans;
}

void solve(){
    // 1 so' lap lai 9 lan thi kieu j cx chia het cho 9
    // ta se dung thuat sinh :))
    cin >> a >> b;
    string ans = "";
    for(int i = 2; i <= (1 << 18); ++i) {
        string tmp = "";
        int j = 0;
        bool ok = true;
        for(; (1<<(j+1)) <= i ; ++j) {
            if (i & (1<<j)) {
                tmp += a;
            } else tmp += b;
            if (tmp[0] == '0') {ok = false; break;}
        }
        if (!ok) continue;
        int cnt_1 = __builtin_popcount(i) - 1;
        // cout << cnt_1 << " " << j <<'\n';
        if (cnt_1 && j - cnt_1 > 0) {
            if (digSum(tmp) % 9 == 0) {
                // cout << tmp << '\n';
                if (ans == "") ans = tmp;
                else if(cmp(tmp, ans)) ans = tmp;
                // cout << ans << "\n";
            }
        }
    }
    cout << ans;
}

int main()
{
    IOS;
    solve();
}