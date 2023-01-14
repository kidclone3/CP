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
    FOR(i, x.size())
    {
        cout << x[i] << " "[i == (int)x.size()-1];
    }
    // cout << "\n";
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

string inp;
// bool neighbour[10][10];
vi neighbour[10];
set<char> check;
int index(char x) {return x - 'A';}

void split() {
    char curr;
    FOR(i, inp.size()) {
        if (i == 0 || inp[i-1] == ';') {
            curr = inp[i];
            check.insert(curr);
        } else if (inp[i] != ':' && inp[i] != ';') {
            // neighbour[index(curr)][index(inp[i])] = 1;
            // neighbour[index(inp[i])][index(curr)] = 1;
            neighbour[index(curr)].push_back(index(inp[i]));
            check.insert(inp[i]);
            // neighbour[index(inp[i])].push_back(index(curr));
        }
    }
}

void solve(){
    check.clear();
    FOR(10) neighbour[i].clear();
    split();
    string permu(all(check));
    vector<pair<int, string>> ans;
    vi pos(10);
    do {
        // int mx = 1;
        // FOR(i, permu.size()) {
        //     pos[index(permu[i])]=i;
        // }
        // FOR(i, 8) {
        //     if (!neighbour[i].empty()) {
        //         EACH(v, neighbour[i]) mx = max(mx, abs(pos[i] - pos[v] + 1));
        //     }
        // }
        // ans.push_back({mx, permu});
        cout << permu << "\n";
    } while(next_permutation(all(permu)));
    // sort(all(ans));
    // print(ans[0].se);
    // cout << " -> " << ans[0].fi << "\n";
    // A B H C G D F E -> 2
    // {
    //     FOR(i, permu.size()) {
    //         pos[index(ans[0].se[i])]=i;
    //     }

    //     // FOR(i, 8) {
    //     //     if (!neighbour[i].empty()) {
    //     //         EACH(v, neighbour[i]) mx = max(mx, abs(pos[i] - pos[v] + 1));
    //     //     }
    //     // }
    //     print(pos);
    // } 
}

int main()
{
    IOS;
    while(getline(cin, inp)) {
        if (inp == "#") break;
        solve();
    }
}