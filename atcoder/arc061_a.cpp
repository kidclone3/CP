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
int n;
vl nums;
vi plusses;
ll ans = 0LL;
void out() {
    ll tmp = 0LL;
    // print(plusses);
    for(int i = 0; i < n-1; ++i) {
        tmp*= 10LL;
        tmp+= nums[i];
        if (plusses[i]) {
            ans += tmp;
            tmp = 0LL;
        }
    }
    tmp*=10LL;
    tmp += nums[n-1];
    ans += tmp;
    // cout << "\t" << ans << "\n";
}

void backtrack(int pos, int len, int k) {
    if (len == k) {
        out();
        return;
    }
    for (int i = pos; i < n-1; ++i) {
        plusses[i] = 1;
        // print(plusses);
        // cout << "\t\t" << len <<"\n";
        backtrack(i+1, len+1, k);
        plusses[i] = 0;
    }
}

void solve(){
    string s; cin >> s;
    EACH(it, s) nums.push_back((it - '0')*1LL);
    n = nums.size();
    // print(nums);
    // k = number of "+".
    for (int k = 0; k < n; ++k) {
        plusses.resize(n, 0);
        backtrack(0, 0, k);
    }
    cout << ans;
}

int main()
{
    IOS;
    solve();
}