#include <bits/stdc++.h>
using namespace std;
#define ll long long
// So sieu nguyen to.

int n;

bool isPrime(ll x) {
    if (x < 2) return false;
    if (x == 2 || x == 3 || x == 5) return true;
    if (x % 2 == 0) return false;
    for(int i = 2; i *i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}
vector<ll> ans;
void check(ll x) {
    ll tmp = x;
    while(x > 0) {
        if (!isPrime(x)) return;
        x /= 10;
    }
    ans.push_back(tmp);
}
ll num = 0LL;
void backtrack(int i) {
    if (i == n) {
        check(num);
        return;
    }
    int j = 0;
    if (!i) j = 1;
    for(; j < 10; ++j) {
        num *= 10;
        num += j;
        backtrack(i+1);
        num /= 10;
    }
}

int main() {
    cin >> n;
    backtrack(0);
    for(auto it : ans) cout << it << '\n';
    return 0;
}