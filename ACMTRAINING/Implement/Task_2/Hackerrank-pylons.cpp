#include <bits/stdc++.h>
using namespace std;

int pylons(int k, vector<int> arr) {
    int n = arr.size();
    // Find the left most power plant.
    int i = -1;
    for(i = k-1; i >= 0; --i) if (arr[i]) {
        break;
    }
    int ans = 1;
    while (i < (int) arr.size()) {
        if (i + k >= n) break;
        int j = i+2*k-1;
        for(j = min(n-1, j); j > i; --j) if (arr[j]){
            break;
        }
        if (j == i) return -1;
        i = j;
        ans++;
    }
    return ans;
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << pylons(k, a);
}
