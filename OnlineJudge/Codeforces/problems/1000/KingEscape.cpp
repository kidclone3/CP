#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
int dRow[] = {-1, 0, 0, 1};
int dCol[] = {0, 1, -1, 0};
const int N = 1e3+5;
bool visited[N][N];
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    IO;
    solve();
}
void solve() {
    int n;
    cin >> n;
    pair<int, int> queen, king, dest;
    cin >> queen.first >> queen.second;
    cin >> king.first >> king.second;
    cin >> dest.first >> dest.second;
    // Chung ta se dung toan, ko dung do thi :))
    

}