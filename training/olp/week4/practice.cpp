#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
    return (a.first < b.first || (a.first == b.first && a.second > b.second));
}

int main() {
    int n; ll c;
    cin >> n >> c;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int i = 0;
    ll curr = c;
    for(; i < n; ++i) {
        if (curr < a[i].first) break;
        curr += a[i].second;
    }
    cout << i;
}