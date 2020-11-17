#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int lo, int hi);
void quickSort(vector<int> &a, int lo, int hi);

int main()
{
    vector<int> inp = {2, 6, 5, 3, 8, 7, 1, 0};
    quickSort(inp, 0, inp.size() - 1);
    for (auto it : inp)
        cout << it << " ";
}
int partition(vector<int> &a, int lo, int hi)
{
    int left = lo;
    int right = hi - 1;
    int mid = (lo + hi) / 2;
    int p = a[mid];
    swap(a[mid], a[hi]);
    while (true)
    {
        while (a[left] < p)
            left++;
        while (a[right] > p)
            right--;
        if (left >= right)
            break;
        else
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    swap(a[left], a[hi]);
    return left;
}
void quickSort(vector<int> &a, int lo, int hi)
{
    if (lo >= hi)
        return;
    int pivot = partition(a, lo, hi);
    quickSort(a, lo, pivot - 1);
    quickSort(a, pivot + 1, hi);
}