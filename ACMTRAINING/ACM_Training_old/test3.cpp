#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {3, 3, 2, 1, 2, 1};
    // a = {3, 2, 1};
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
    set<int> st;
    multiset<int> st2;
    st.insert(a.begin(), a.end());
    st2.insert(a.begin(), a.end());
    st.insert(10);
    st.insert(0);
    st2.insert(10);
    st2.insert(0);

    auto tmp = lower_bound(st2.begin(), st2.end(), 2);
    st2.erase(tmp);
    for (auto it : st2) {
        cout << it << " ";
    }
    cout << "\n";
    vector<int> b = a;
    unique(b.begin(), b.end());
    for (auto it : b) {
        cout << it << " ";
    }
    // cout << "\n" << st2.count(2);
    // auto it = st.begin();
    // // it++;
    // advance(it, 2);
    // cout << *it;

}
