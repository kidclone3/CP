#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+5;

long candies(int n, vector<int> arr) {
    vector<int> a (n+4, 0), res(n+4, 0);
    a[0] = -inf;
    a[n+1] = inf;
    for (int i = 0; i < n; i++)
    {
        a[i+1] = arr[i];
    }
    stack<int> suspect;
    for (int i = 1; i <= n; ++i) {
        if (a[i-1] < a[i] && a[i] <= a[i+1]) {
            res[i] = res[i-1] + 1;
        }
        else if (a[i-1] >= a[i] && a[i] <= a[i+1]) {
            res[i] = 1;
        }
        else {
            suspect.push(i);
        }
    }
    while(!suspect.empty()) {
        int i = suspect.top();
        if (a[i-1] < a[i] && a[i] > a[i+1]) {
            res[i] = max(res[i-1], res[i+1]) + 1;
        }
        else {
            res[i] = res[i+1] + 1;
        }
        // cout << i << " ";
        suspect.pop();
    }
    // cout << '\n';
    long ans = 0;
    for (int i = 1; i < n+1; i++) {
        ans+=res[i];
        // cout << res[i] << " ";
    }
    // cout << "\n";
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << candies(n, a);
}