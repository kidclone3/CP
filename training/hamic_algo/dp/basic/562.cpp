#include<bits/stdc++.h>
using namespace std;

const int maxW = 500*100+5;

void solve() {
    int n; cin >> n;
    vector<int> coins(n);
    int maxSum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> coins[i];
        maxSum += coins[i];
    }
    bitset<maxW> possible;
    possible[0] = true;
    set<int> values;
    for(auto coin : coins) {
        for(int w = maxSum; w >= 0; --w) {
            if (possible[w] && w + coin <= maxSum) {
                possible[w+coin] = true;
                values.insert(w+coin);
            }
        }
    }
    auto find = values.lower_bound(maxSum/2);
    int value1, value2;
    value1 = value2 = *find;
    if (find != values.begin()) value2 = *(--find);
    cout << min(abs(2*value1 - maxSum), abs(2*value2 - maxSum)) << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}