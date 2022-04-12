#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {1,2,3,4,5,6,7};
    int n = a.size();
    int d = 2;
    // Dau tien, dao mang A co' do dai la d.
    for(int i = 0; i < d/2; ++i) {
        swap(a[i], a[d-i-1]);
    }
    // Tiep theo, dao mang B co' do dai n - d.
    for(int i = d; i < d + (n-d)/2; ++i) {
        swap(a[i], a[n-1-i+d]);
    }
    // Cuoi cung, swap mang A 1 lan cuoi.
    for(int i = 0; i < n/2; ++i) {
        swap(a[i], a[n-1-i]);
    }
    // In mang a ra de ktra.
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
}
