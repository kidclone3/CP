// https://oj.vnoi.info/problem/binary
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
const int N = 100;
int c[N][N];
void solve(int n, int k);
int nCk(int n, int k) {
    if (k == 0 || k == n) {
        c[n][k] = 1;
        return 1; 
    }
    if (k==1 || k == n-1) {
        c[n][k] == n;
        return n;
    }
    if (c[n][k] != 0) return c[n][k];
    else {
        c[n][k] = nCk(n-1, k-1) + nCk(n-1, k);
        return c[n][k];
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    int n, k;
    while(cin >> n >> k) {
        solve(n, k);
    }
    
}
void solve(int n, int k) {
    int i = 0;
    while((1<<(i+1)) < n) i++;
    cout << nCk(i, k) << "\n";
}