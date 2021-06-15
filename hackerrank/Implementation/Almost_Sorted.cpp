#include <bits/stdc++.h>
using namespace std;

void almostSorted(vector<int> arr) {
    int n = arr.size();
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "yes";
        return;
    }
    vector<int> a = arr;
    sort(a.begin(), a.end());
    int l, r;
    l = 0, r = n - 1;
    while(l < n && arr[l] == a[l]) {
        l++;
    }
    while(r > -1 && arr[r] == a[r]) {
        r--;
    }
    swap(arr[l], arr[r]);
    if(is_sorted(arr.begin(), arr.end())) {
        cout << "yes\n";
        l++,r++;
        cout << "swap " << l << " " << r;
        return;
    }
    swap(arr[l], arr[r]);
    reverse(arr.begin() + l, arr.begin() + r + 1);
    if (is_sorted(arr.begin(), arr.end())) {
        cout << "yes\n";
        l++, r++;
        cout << "reverse " << l << " "<< r;
    }
    else {
        cout << "no";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    almostSorted(a);
}
