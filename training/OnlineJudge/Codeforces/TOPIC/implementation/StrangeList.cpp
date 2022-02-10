// https://codeforces.com/problemset/problem/1471/B
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

void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n;
    ll x;
    cin >> n >> x;
    queue<pair<ll, int>> q;
    ll sum = 0;
    FOR(i, n) {
        ll a;
        cin >> a;
        q.push({a, 1});
    }
    while (!q.empty()) 
    {
        auto now = q.front();
        q.pop();
        sum += now.first * now.second;
        if (now.first % x == 0) {
            q.push({now.first / x, x * now.second});
        }
        else {
            break;
        }
    }
    while(!q.empty()) {
        sum += q.front().first * q.front().second;
        q.pop();
    }
    cout << sum <<"\n";
    
}