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

const int N = 2* 100 + 5;
vector<string> a;
string ans;
int n;
vi pairs[N];
bool check(string &pref, string &suff) {
    string s = pref + suff.substr(n - 2);
    ans.resize(2*n-2, ' ');
    vb visited(2*n-2, 0);
    FOR(i, 1, n) {
        int p1 = pairs[i][0];
        int p2 = pairs[i][1];
        string str1 = s.substr(0, i);
        string str2 = s.substr(n - i, i);
        if (a[p1] == str1 && a[p2] == str2) {
            ans[p1] = 'P'; ans[p2] = 'S';
        }
        else if (a[p2] == str1 && a[p1] == str2) {
            ans[p1] = 'S'; ans[p2] = 'P';
        }
        else return false;
    }
    return true;
}

void solve(){
    cin >> n;
    a.resize(2*n-2);
    vector<string> big;
    FOR(2*n - 2) {
        cin >> a[i]; 
        pairs[(int) a[i].size()].push_back(i);
        if (a[i].size() == (size_t) n - 1) big.push_back(a[i]);
    }
    if (check(big[0], big[1])) cout << ans;
    else if (check(big[1], big[0])) cout << ans;
}

int main()
{
    IOS;
    solve();
}