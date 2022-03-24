// I think this code could AC the math problem of my Optimization teacher.
/**
  *   author: delus
**/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;


// Disable this pragma by default because of debugging
// 2 pragma lines give compiler information to use SIMD instruction for optimize code.
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")


#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
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

// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
//
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

// Small tips on unordered_map to not be tle:
// unordered_map<int, int> mp;
// mp.max_load_factor(0.25);
// mp.reserve(1<<20);

// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[] = {1,1,0,-1,-1,-1, 0, 1};
int dy[] = {0,1,1, 1, 0,-1,-1,-1};  // S,SE,E,NE,N,NW,W,SW neighbors

int n;

const int MAX = 1<<8;
// We need to bound of each layer.
vi layer = {0, 1, 3, 6, 10, 15, 21, 28};
vector<int> ans; // Store the values of exact ...
bitset<MAX> mark; // Mark used numbers.
bool found = false;
void backtrack(int i, int val) {
    // print(ans);
    
    // if (found) return;
    cout << i << " ";
    int lay_number = lower_bound(all(layer), i) - layer.begin();

    // if (i == 10) cout << ans[i] << " " << lay_number << "\n";
    // if (lay_number == n+1 && (int) mark.count() == layer[lay_number-1]) {
    //     found = true;
    //     return;
    // }
    if (i == layer[n] && (int)mark.count() == layer[n]) {
        FOR(jj, 1, layer[n]+1) cout << ans[jj] << " ";
        cout << '\n';
        found = true;
        return;
    }
    // if (layer[lay_number] != i) lay_number--;
    if (i == layer[lay_number]) {
        if (ans[i] - ans[i-1] != ans[layer[lay_number-1]]) return;
        backtrack(i+1, 0);
    }
    else 
    if (i == layer[lay_number-1]+1) {
        int top = ans[layer[lay_number-2]+1];
        for(int j = 1; j <= layer[n]; ++j) {
            // get the top values.
            if (!mark[j] && (j+top <= layer[n]) && !mark[j+top]) {
                mark[j] = mark[j+top] = true;
                ans[i] = j;
                ans[i+1] = j+top;
                backtrack(i+1, j+top);
                // if (found) return;
                mark[j] = mark[j+top] = false;
                ans[i] = ans[i+1] = -1;
            }
            if (!mark[j] && (j-top >= 1) && !mark[j-top]) {
                mark[j] = mark[j-top] = true;
                ans[i] = j;
                ans[i+1] = j-top;
                backtrack(i+1, j-top);
                // if (found) return;
                mark[j] = mark[j-top] = false;
                ans[i] = ans[i+1] = -1;
            }
        }
    }
    else { lay_number--;
        int j = i - layer[lay_number];
        int top = ans[j + layer[lay_number-1]];
        cerr << ans[i] << " " << top << ans[i+1] <<"\n";
        if (val+top <= layer[n] && !mark[val+top]) {
            ans[i+1] = val+top;
            mark[val+top] = true;
            backtrack(i+1, val+top);
            // if (found) return;
            ans[i+1] = -1;
            mark[val+top] = false;
        }
        if (val-top >= 1 && !mark[val-top]) {
            ans[i+1] = val-top;
            mark[val-top] = true;
            backtrack(i+1, val+top);
            // if (found) return;
            ans[i+1] = -1;
            mark[val-top] = false;
        }
    }
}

int solve() {
    cin >> n;
    ans.resize(n*(n+1)/2+5, -1);
    mark.reset();
    for(int k = 1; k <= n; ++k) {
        mark[k] = true;
        ans[1] = k;
        backtrack(2, k);
        if (found) break;
        mark.reset();
        // memset(ans, -1, sizeof ans);
        fill(all(ans), -1);
    }
    if (found) {
        FOR1(layer[n]) cout << ans[i] << " ";
    }
    return 0; 
}

int main()
{
    IOS;
    solve();
}

