#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
// 2 pragma lines give compiler information to use SIMD instruction for optimize code.
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")


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

template <class T>
void printPair2(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", {" << it.second.first << " " << it.second.second << "} ) ";
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

// Small tips on unordered_map to not be tle:
// unordered_map<int, int> mp;
// mp.max_load_factor(0.25);
// mp.reserve(1<<20);

// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

#define add1 st.insert({it1_f, it1_s})
#define add2 st.insert({it2_f, it2_s})
const int N = 1e3+5;
int cnt[N];

// first = vi tri, second = so luong.


int solve() {
    int n; cin >> n;
    vii pos[n+5], pp(n*n);
    vi a(n*n), cc(n*n);
    FOR(n*n) {
        cin >> a[i];
        cnt[a[i]]++;
        pp[i] = {a[i], i};
    }
    sort(all(pp));
    set<ii> st;
    FOR(n+5) {
        if (cnt[i]) st.insert({cnt[i], i});
    }
    bool ok = true;
    int p = 1;
    
    while(!st.empty()) {
        auto it1 = prev(st.end());
        int it1_f, it1_s;
        tie(it1_f, it1_s) = *it1;
        if (st.size() == 1) {
            if (it1_f % n != 0) {
                ok = false;
                break;
            } else {
                // tru n.
                it1_f -= n;
                pos[it1_s].push_back({p, n});
                
                st.erase(it1);
                // Neu du thi nhet lai vao.
                if (it1_f > 0) {
                    add1;
                    p++;
                }
            }
            continue;
        }
        // auto it2 = prev(prev(st.end()));
        auto it2 = st.begin();
        int it2_f, it2_s;
        tie(it2_f, it2_s) = *it2;
        if (it2_f % n == 0) {
            it2_f -= n;
            st.erase(it2);
            pos[it2_s].push_back({p, n});
            if (it2_f > 0) {
                add2;
            }
            
        } else {
            int rem = n - it2_f % n;
            if (it1_f < rem) {
                ok = false;
                break;
            }
            pos[it2_s].push_back({p, it2_f % n});
            pos[it1_s].push_back({p, rem});
            it2_f -= it2_f%n;
            it1_f -= rem;
            st.erase(it1);
            st.erase(it2);
            if (it1_f > 0) add1;
            if (it2_f > 0) add2;
        }
        p++;
    }

    // print(a);
    // printPair(pp);
    if (ok) {
        cout << "YES\n";
        int i = 0;
        EACH(it, pos) {
            while(!it.empty()) {
                int str = i;
                for(; i < str + it.back().second; ++i) {
                    cc[pp[i].second]=it.back().first;
                }
                it.pop_back();
            }
        }
        print(cc);
    }
    else cout << "NO\n";
    
    return 0; 
}

int main()
{
    IOS;
    solve();
}

