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

int n; 

bool found(int &x1, int y1, int &x2, int y2) {
    if (y2 < y1) {
        swap(x1, x2);
        swap(y1, y2);
    }
    
    for(int i = 1; i <= y1; ++i) {
        if ((n - 1 - i * y2) % y1 == 0) {
            x1 = i;
            x2 = (n - 1 - i * y2)/y1;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n;
    for(int i = 2; i * i <= n; ++i){
        if (n % i == 0) {
            if (i != n/i) {
                int x1, x2;
                if (found(x1, i, x2, n/i)) {
                    cout << "YES\n2\n";
                    cout << x1 << " " << i << "\n" << x2 << " " << n/i <<'\n';
                    return;
                }
            }
        }
    }
    cout << "NO";
}

int main()
{
    IOS;
    solve();
}