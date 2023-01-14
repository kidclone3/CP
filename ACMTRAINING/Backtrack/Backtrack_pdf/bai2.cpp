#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n, k;
int avg;
vector<int> mark;


bool found = false;
void check() {
    vector<int> cnt(k, 0);
    for(int i = 0; i < n; ++i) {
        cnt[mark[i]] += a[i];
    }
    for(int i = 0; i < k; ++i) {
        if (cnt[i] != avg) return;
    }
    // cerr << '\n';
    found = true;
}

void backtrack(int i) {
    if (found) return;
    if (i == n) {
        check();
        return;
    }
    for(int j = 0; j < k; ++j) {
        mark[i] = j;
        backtrack(i+1);
        if (found) return; 
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    mark.resize(n);
    avg = 0;
    for(int i = 0; i < n; ++i) cin >> a[i], avg += a[i];
    if (avg % k != 0) return cout << "Not found 1", 0;
    avg /= k;
    backtrack(0);
    cerr << avg << '\n';
    if (found) {
        vector<int> ans[k];
        for(int i = 0; i < n; ++i) {
            ans[mark[i]].push_back(a[i]);
            cerr << mark[i] << " \n"[i==n-1]; 
        }
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < (int) ans[i].size(); ++j) cout << ans[i][j] << " \n"[j == (int)ans[i].size()-1];
        }
    } else cout << "Not found";
    return 0;
}
