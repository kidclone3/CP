#include <bits/stdc++.h>
using namespace std;
int partition(int lo, int hi);
void qsort(int lo, int hi);
void sortElement(vector<int> &nums);
int getPower(int k);
int getKth(int lo, int hi, int k);
int main()
{
    int lo = 12;
    int hi = 15;
    int k = 2;
    //freopen("out.txt", "w", stdout);
    cout << getKth(lo, hi, k) << "\n";
}

int getPower(int k)
{
    int count = 0;
    while (k > 1)
    {
        if (k % 2 == 0)
        {
            k /= 2;
            count++;
        }
        else
        {
            k = 3 * k + 1;
            count++;
        }
    }
    return count;
}
int getKth(int lo, int hi, int k)
{
    vector<pair<int, int>> nums;
    for (int i = lo; i <= hi; i++)
    {
        nums.push_back({getPower(i), i});
    }
    //bbsort();
    sort(nums.begin(), nums.end());

    return nums[k - 1].second;
}