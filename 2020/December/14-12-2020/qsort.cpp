#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void qsort(vi &arr, int left, int right)
{
    if (left>=right) return;
    int mid=arr[(left+right)/2];
    int i=left;
    int j=right;
    while (i<=j) 
    {
        while (arr[i] < mid) i++; // Xet tu dau den pivot, dung lai o phan tu nao lon hon mid

        while (arr[j] > mid) j--;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    qsort(arr, i, right);
    qsort(arr, left, j);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vi arr={38,27,43,3,9,82,10};
    qsort(arr, 0, arr.size()-1);
    print(arr);
}