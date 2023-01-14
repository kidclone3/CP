#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

const int N = 2*1e6+5;

int n, q;
int sz;
ll T[N];

void update(int i, int val) {
    for(; i <= sz; i += i & (-i)) 
        T[i] += val;
}

ll get(int i) {
    ll res = 0LL;
    for(; i > 0; i -= i&(-i)) 
        res += T[i];
    return res;
}

int solve() {
    cin >> n >> q;
    vi arr(n);
    // Cần rời rạc hóa, nên các truy vấn phải xử lý offline.
    vi st; // Dùng set để rr hóa cho khỏe.
    // set<int> st;
    FOR(n) {
        cin >> arr[i];
        st.push_back(arr[i]);
    }
    vector<vi> queries(q);
    FOR(q) {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        if (ch == '?') {
            st.push_back(a);
            st.push_back(b);
            queries[i] = {0, a, b};
        } else {
            queries[i] = {1, a, b};
            st.push_back(b);
        }
    }
    // print(st);
    sort(all(st));
    // print(st);
    // unordered_map<int, int, custom_hash> mp;
    unordered_map<int, int> mp;
    mp.max_load_factor(0.25);
    mp.reserve(1<<20);
    int i = 1;
    EACH(it, st) {
        if (mp[it] == 0)
            mp[it] = i++;
    }

    // printPair(mp);
    sz = mp.size() + 5;
    // EACH(it, st) update(mp[it], 1);
    // cout << sz << '\n';
    // Preprocessing has done!
    FOR(n) {
        update(mp[arr[i]], 1);
    }
    FOR(q) {
        if (queries[i][0]) {
            int k = queries[i][1];
            int val = queries[i][2];
            update(mp[arr[k-1]], -1);
            update(mp[val], 1);
            arr[k-1] = val;
        } else {
            int l, r;
            l = queries[i][1];
            r = queries[i][2];
            int ans = get(mp[r]) - get(mp[l]-1);
            cout << ans << '\n';
        }
    }
    cout << " ";
    return 0; 
}

int main()
{
    IOS;
    solve();
}