#include <bits/stdc++.h>
using namespace std;

vector<int> largestPermutation(int k, vector<int> arr) {
    vector<int> index(arr.size() + 1);
    for (int i = 0; i < (int) arr.size(); ++i) {
        index[arr[i]] = i;
    }
    int nn = arr.size();
    for (int i = 0; i < (int) arr.size(); ++i) {
        if (k == 0) break;
        if (arr[i] < nn) {
            int tmp = arr[i];
            swap(arr[i], arr[index[nn]]);
            int tmp2 = index[nn];
            index[nn] = i;
            index[tmp] = tmp2;
            k--;
        }   
        nn--;
    }
    return arr;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b = largestPermutation(k, a);
    for (auto &it : b) {
        cout << it << " ";
    }
}