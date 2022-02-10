#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a[5];
    a[2].push_back(1);
    swap(a[2], a[1]);
    cout << a[1].size() << " " << a[2].size() << " ";
}