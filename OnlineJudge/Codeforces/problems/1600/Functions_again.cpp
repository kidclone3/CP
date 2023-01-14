// https://codeforces.com/contest/788/problem/A
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int n; cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        b[i] = abs(a[i]-a[i+1])*(ll)pow(-1, i);
        c[i] = abs(a[i]-a[i+1])*(ll)pow(-1, i+1);
    }
    // using kadane's algorithm.
    ll curr = 0;
    ll mx = LLONG_MIN;
    for(int i = 0; i < n-1; ++i) {
        curr += b[i];
        mx = max(mx, curr);
        if (curr < 0) curr = 0;
    }
    curr = 0;
    for (int i = 1; i < n-1; i++)
    {
        curr += c[i];
        mx = max(mx, curr);
        if (curr < 0) curr = 0;
    }
    cout << mx;
}