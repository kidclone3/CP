#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        // int tmp;
        // cin >> tmp;
        // a.push_back(tmp);
        cin >> a[i];
    }
    unordered_set<int> st;
    for (int i = 0; i < n; ++i) {
        if (!st.count(a[i])) {
            cout << a[i] << " ";
            st.insert(a[i]);
        }
    }
}