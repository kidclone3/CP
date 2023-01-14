#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    stack<int> st;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (st.empty()) cout << 0 << " ";
        else cout << st.top() + 1 << " ";
        st.push(i);
    }
}
