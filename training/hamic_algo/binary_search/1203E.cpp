#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    set<int> st;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    for(int i = 0; i < n; ++i) {
        if (st.count(max(a[i]-1, 1)) == 0) st.insert(max(a[i]-1, 1));
        else if (st.count(a[i]) == 0) st.insert(a[i]);
        else if (st.count(a[i]+1) == 0) st.insert(a[i]+1);
    }
    cout << st.size();
}