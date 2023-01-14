#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
// #pragma GCC optimize("O3,unroll-loops")

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
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
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

class newQueue {
    public:
    // {element, {minEle, maxEle}}
    stack<pair<int, ii>> s1, s2;
    int minEle, maxEle;
    void insert(int x) {
        minEle = maxEle = x;
        if (!s1.empty()) {
            auto tmp = s1.top();
            minEle = min(minEle, tmp.se.fi);
            maxEle = max(maxEle, tmp.se.se);
        }
        s1.push({x, {minEle, maxEle}});
    }

    void findPeek() {
        if (s1.empty() || s2.empty()) {
            minEle = s1.empty() ? s2.top().se.fi : s1.top().se.fi;
            maxEle = s1.empty() ? s2.top().se.se : s1.top().se.se;
        } else {
            minEle = min(s1.top().se.fi, s2.top().se.fi);
            maxEle = max(s1.top().se.se, s2.top().se.se);
        }
        // return {minEle, maxEle};
    }
    bool isValid(int d) {
        findPeek();
        return maxEle - minEle <= d;
    }
    
    void remove() {
        if (s2.empty()) {
            while(!s1.empty()) {
                int element = s1.top().fi;
                s1.pop();
                minEle = s2.empty() ? element : min(element, s2.top().se.fi);
                maxEle = s2.empty() ? element : max(element, s2.top().se.se);
                s2.push({element, {minEle, maxEle}});
            }
        }
        s2.pop();
    }
} st;

int solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    FOR(n) cin >> a[i];
    int ans = 1;
    int l = 0;
    FOR(n) {
        st.insert(a[i]);
        while(l < i && !st.isValid(q)) {
                st.remove();
                l++;
        }
        ans = max(ans, i-l+1);
    }
    cout << ans;
    return 0; 
}

int main()
{
    IOS;
    solve();
}