#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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

const int MAXLEN = 100*100 + 5;

void solve(){
    int L; cin >> L;
    L *= 100;
    vi cars;
    while(1) {
        int curlen;
        cin >> curlen;
        if (curlen == 0) break;
        else cars.push_back(curlen);
    }
    int n = cars.size();
    vector<vi> pre(n+5, vi(L+5, -1));
    vector<bitset<MAXLEN>> dp(2);
    dp[0][0] = true;
    // we while use saving trick, however I didn't understand it much
    int t = 0, pt;
    int lastlen = 0;
    int sumlen = 0; 
    int i = 0;
    int N = 0; // how many cars we could store.

    // if (cars.empty()) return void(cout << "0\n");
    EACH(curlen, cars) {
        pt = t, t ^= 1;
        sumlen += curlen;
        i++;
        dp[t].reset(); // initialize new row for dp table
        bool canload = false;
        FOR(len, 0, L+1) {  // enumerate all possible length of the port side.
            if (dp[pt][len] == false) continue; // there is no solution for this state, ignore
            if (len + curlen <= L && sumlen - (len + curlen) <= L) {// port and starboard are ok. 
                dp[t][len + curlen] = true;
                pre[i][len + curlen] = 0;
                lastlen = len + curlen;
                canload = true;
            }

            if (sumlen - len <= L) {
                dp[t][len] = true;
                pre[i][len] = 1;
                lastlen = len;
                canload = true;
            }
        }
        if (!canload) break;
        else N = i;
    }
    cout << N << "\n";
    // cout << lastlen <<'\n';
    vi answer;
    FOR(j, N, 0, -1) {
        if (pre[j][lastlen] == 0) {
            lastlen -= cars[j-1];
            answer.push_back(0);
        } else if (pre[j][lastlen] == 1) {
            answer.push_back(1);
        }
    }
    reverse(all(answer));
    int head = 0;
    if (!answer.empty()) head = answer[0];
    EACH(it, answer) {
        // cout << (it == 0 ? "starboard" : "port") << "\n";
        cout << (it == head ? "port" : "starboard") << "\n";
    }
}

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) {
        solve();
        if (t) cout << "\n";
    }
}