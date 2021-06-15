#include <bits/stdc++.h>
using namespace std;

int pylons(int k, vector<int> arr) {
    int n = arr.size();
    int i;
    for(i = k-1; i >= 0; --i) {
        if (arr[i] == 1) break;
    }
    int ans = 1;
    if (i == -1) return -1;
    while( i < arr.size()) {
        if (i + k >= n) break;
        int j = i + (2*k - 1);
        for(j = min(n-1, j); j > i; --j) {
            if (arr[j] == 1) break;
        }
        if (i == j) {
            return -1;
        }
        ans++;
        i = j;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << pylons(k, a);
}