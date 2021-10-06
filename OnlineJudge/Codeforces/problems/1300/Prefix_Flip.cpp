#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
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

void reverse(string &a, int len) {
    string b;
    FOR(i, len) {
        b.push_back((a[i] == '0' ? '1' : '0'));
    }
    reverse(all(b));
    a = b + a.substr(len, a.size() - len);
}

void solve(){
    int n; cin >> n;
    string a, b;
    cin >> a >> b;
    int j = n - 1;
    vi ans;
    while(j > -1) {
        if (a[j] != b[j]) {
            if (a[0] != b[j]) {
                ans.push_back(j+1);
                reverse(a, j+1);
            }
            else {
                ans.push_back(1);
                reverse(a, 1);
                if (a[j] != b[j]) {
                    ans.push_back(j+1);
                    reverse(a, j+1);
                }
            }
        }
        // cout << "a = " << a << "\nb = " << b << "\n\n";
        j--;
    }
    cout << ans.size() << " ";
    print(ans);
    
}   

int main()
{
    IOS;
    int t; cin >> t;
    while(t--) solve();
}