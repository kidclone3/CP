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
string s;
int n;
bool dream(int i) {
    if (i + 5 > n) return false;
    string sub = s.substr(i, 5);
    return sub == "maerd";
}
bool erase(int i) {
    if (i + 5 > n) return false;
    string sub = s.substr(i, 5);
    return sub == "esare";
}
bool dreamer(int i) {
    if (i + 7 > n) return false;
    string sub = s.substr(i, 7);
    return sub == "remaerd";
}
bool eraser(int i) {
    if (i + 6 > n) return false;
    string sub = s.substr(i, 6);
    return sub == "resare";
}
void solve(){
    cin >> s;
    // string tmp = "";
    n = s.size();
    int i;
    reverse(all(s));
    for(i=0; i < n;) {
        if (i > n-5) break;
        string sub = s.substr(i, 3);
        if (sub == "res") {
            if (eraser(i)) i+=6;
            else break;
        }
        else if (sub == "rem") {
            if (dreamer(i)) i+=7;
            else break;
        }
        else if (dream(i) || erase(i)) i+=5;
        else break;
    }
    // cout << i << '\n';
    cout << (i==n ? "YES" : "NO");
}

int main()
{
    IOS;
    solve();
}