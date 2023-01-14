#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    int mid = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // mid += a[i];
    }
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = -105; i < 105; i++)
    {
        int ans2 = 0;
        for (int j = 0; j < n; j++)
        {
            ans2 += (a[j] - i) * (a[j] - i);
        }
        ans = min(ans, ans2);
    }
     
    cout << ans;
}