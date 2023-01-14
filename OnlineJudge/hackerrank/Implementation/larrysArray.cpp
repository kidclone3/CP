#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &a, int l, int &i) {
    if (i == l) i = l + 2;
    else if (i == l + 1) i = l;
    else if (i == l + 2) i = l + 1;
    swap(a[l], a[l+1]);
    swap(a[l+1], a[l+2]);
}
string larrysArray(vector<int> A) {
    int start = 0;
    int n = A.size();
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = start; j < n; ++j) {
            if (A[j] == i) {
                while(j > start) {
                    if (j - 2 >= start) {
                        rotate(A, j-2, j);
                    }
                    else if (j - 1 >= start) {
                        rotate(A, j-1, j);
                    }
                }
                start++;
                break;
            }
        }
    }
    for (int i = n - 3; i < n-1; i++)
    {
        if (A[i] >= A[i+1]) return "NO";
    }
    
    return "YES";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << larrysArray(a) << "\n";
    }
}