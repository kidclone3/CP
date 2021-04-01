#include <bits/stdc++.h>
using namespace std;
int main() {
    set<int> st;
    for(int i = 1; i<=5; ++i) {
        st.insert(i);
    }
    auto it = st.rbegin();
    for(; it!=st.rend(); ++it) {
        cout<<*it <<'\n';
    }
}