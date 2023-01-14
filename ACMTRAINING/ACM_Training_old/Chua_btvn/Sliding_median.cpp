#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};

multiset<int> lefts, rights;
int n, k;

void balance() {

    if (k&1) {
        while(lefts.size() < k/2 + 1) {
            lefts.insert(*rights.begin());
            rights.erase(rights.begin());
        }
    }
    else {
        while(lefts.size() < k/2) {
            lefts.insert(*rights.begin());
            rights.erase(rights.begin());
        }
    }
    while(!rights.empty () && !lefts.empty() && *lefts.rbegin() > *rights.begin()) {
        rights.insert(*lefts.rbegin());
        auto it = lower_bound(lefts.begin(), lefts.end(), *lefts.rbegin());
        lefts.erase(it);
        lefts.insert(*rights.begin());
        rights.erase(*rights.begin());
    }
}
void remove(int x) {
    auto it1 = lower_bound(lefts.begin(), lefts.end(), x);
    auto it2 = lower_bound(rights.begin(), rights.end(), x);
    if (it1 != lefts.end() && *it1 == x) {
        lefts.erase(it1);
    }
    else {
        rights.erase(it2);
    }
}
int main() {
    cin >> n >> k;
    // Size left + size right = k;
    // i < k => them vao.
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i < k) {
            rights.insert(a[i]);
        }
    }
    balance();
    // print(rights);
    cout << *lefts.rbegin() << " ";
    for (int i = k; i < n; ++i) {
        remove(a[i-k]);
        rights.insert(a[i]);
        balance();
        cout << *lefts.rbegin() << " ";
        // print(lefts);
        // print(rights);
    }

}
