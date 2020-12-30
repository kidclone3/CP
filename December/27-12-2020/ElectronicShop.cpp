#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector <int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int mid = (left + right) >> 1;
    while (left != mid && right != mid) {
        if (arr[mid] == target || (arr[mid] < target && arr[mid+1] > target)) {
            return arr[mid];
        }
        if (arr[mid] > target) {
            right = mid -1;
        }
        else {
            left = mid;
        }
        mid = (left + right) >> 1;
    }
    for (int i = right; i >= left; --i) {
        if (arr[i] <= target) {
            return arr[i];
        }
    }
    return 0;
}
int getMoneySpent(vector<int> &keyboards, vector<int> &drives, int b) {
    /*
     * Write your code here.
     */
    int res = -1;
    sort (keyboards.begin(), keyboards.end());
    sort (drives.begin(), drives.end());
    for (auto i = keyboards.rbegin(); i!=keyboards.rend(); ++i) {
        if (*i >= b) continue;
        int search = binarySearch(drives, b - *i);
        if (search != 0) {
            res = max(res, *i + search);
        }      
    }
    return res;
}

int main()
{
    int b, n, m;
    cin>> b >> n >> m;
    vector<int> keyboards, drives;
    for (int i=0; i<n; ++i) {
        int temp; 
        cin >> temp;
        keyboards.push_back(temp);
    }
    for (int i=0; i<m; ++i) {
        int temp; 
        cin >> temp;
        drives.push_back(temp);
    }
    cout<<getMoneySpent(keyboards, drives, b);
}