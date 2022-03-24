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
// vi layer = {0, 1, 3, 6, 10, 15, 21, 28};
vi layer;
vector<int> ans; // Store the values of exact ...
bitset<MAX> mark; // Mark used numbers.
bool found = false;

bool inside(int x) {
    return 1 <= x && x <= layer[n];
}

void backtrack(int pos, int val) {
    if (found) return;
    auto current_layer = lower_bound(all(layer), pos);
    // auto current_layer_idx= it-layer.begin();
    if (pos > layer[n]) { // found a feasible solution
        found = true;
        return;
    }
    if (*current_layer == pos) { // End of row, we need to check if it is right with the top.

        int top = ans[pos-*prev(current_layer)-1]; 
        if (abs(ans[pos] - ans[pos-1]) != top) return; // wrong.
        else backtrack(pos+1, val); // else continue to backtrack.

    } else if (pos == (*prev(current_layer) - 1)) { // if the first element of row
        int top = ans[*prev(current_layer)+1]; // values 
        FOR(j, 1, layer[n]+1) {
            if (inside(j+top) && !mark[j] && !mark[j+top]) {
                mark[j] = mark[j+top] = true;
                ans[pos] = j;
                ans[pos+1] = j+top;
                backtrack(pos+1, j+top);

                mark[j] = mark[j+top] = false;
                ans[pos] = ans[pos+1] = -1;
            }
            if (inside(j-top) && !mark[j] && !mark[j-top]) {
                mark[j] = mark[j-top] = true;
                ans[pos] = j;
                ans[pos+1] = j-top;
                backtrack(pos+1, j-top);

                mark[j] = mark[j-top] = false;
                ans[pos] = ans[pos+1] = -1;
            }
        }
    } else { // inside the row.
        // there are 2 cases:
        // ans[i+1] = val + top  or   val - top;
        // top = pos - *prev(current_layer);
        int top = ans[pos - *prev(current_layer)]; // values 
        if (inside(val+top) && !mark[val+top]) {
            mark[val+top] = true;
            ans[pos+1] = val+top;
            backtrack(pos+1, val+top);

            mark[val+top] = false;
            ans[pos+1] = -1; 
        }
        if (inside(val-top) && !mark[val-top]) {
            mark[val-top] = true;
            ans[pos+1] = val-top; 
            backtrack(pos+1, val-top);
            
            mark[val-top] = false;
            ans[pos+1] = -1;
        }
    }
}

int solve() {
    cin >> n;
    ans.resize(layer[n]+5);
    FOR1(n) {
        mark[i] = true;
        ans[1] = i;
        backtrack(2, i);
        if (found) break;

        mark.reset();
        ans.clear();
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
    FOR(100) layer.push_back(i*(i+1)/2);
    solve();
}

