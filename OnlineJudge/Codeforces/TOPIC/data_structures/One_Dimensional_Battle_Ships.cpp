// https://codeforces.com/problemset/problem/567/D
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
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

void solve(){
    int n, k, a, m;
    cin >> n >> k >> a >> m;
    vi shots(m);
    FOR(m) cin >> shots[i];
    set<pair<pii, int>> board;
    int ships = 1 + (n-a)/(a+1);
    int remain, len;
    board.insert({{1, n}, ships});
    bool found = false;
    int i = 0;
    for (; i < m && ships >= k; ++i) {
        auto it = board.lower_bound({{shots[i], 0}, 0});
        if (it == board.end() || it->first.first != shots[i]) --it;
        auto tmp = *it;
        board.erase(it);
        
        if (tmp.first.first == shots[i]) {
            len = tmp.first.second - 1;
            if (len >= a) {
                remain = 1 + (len-a) / (a+1);
                board.insert({{shots[i]+1, len}, remain});
                ships -= tmp.second - remain;
            }
            else {
                ships -= tmp.second;
                board.insert({{shots[i]+1, len}, 0});
            }
        }
        else {
            int ships_remain = 0;
            pair<pii, int> left = {{tmp.first.first, shots[i] - tmp.first.first}, 0};
            len = left.first.second;
            if (len >= a) {
                remain = 1 + (len-a)/(a+1);
                left.second = remain;
                ships_remain += remain;
            }
            board.insert(left);
            if (shots[i] + 1 <= n) {
                pair<pii, int> right = {{shots[i]+1, tmp.first.second-left.first.second-1}, 0};
                len = right.first.second;
                if (len >= a) {
                    // board.insert(right);
                    remain = 1 + (len-a)/(a+1);
                    right.second = remain;
                    ships_remain += remain;
                }
                board.insert(right);
            }
            ships -= tmp.second - ships_remain;
        }
        // cout << i+1 << '\n';
        // EACH(it2, board) {
        //     cout << "Pos = " << it2.first.first << ",Len = " << it2.first.second << ", Ships = " << it2.second << "\n";
        // }
        // cout << "\n";
        if (ships < k) found = true;
    }
    cout << (found ? i : -1);

}

int main()
{
    IOS;
    solve();
}