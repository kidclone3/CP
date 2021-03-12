#include <bits/stdc++.h>
using namespace std;

int findIndexI(vector<int> nums, int lo, int hi);

int main()
{
    vector<int> nums = {1, 3, 3, 3, 6, 9, 10};
    cout << findIndexI(nums, 0, nums.size() - 1);
}
int findIndexI(vector<int> nums, int lo, int hi)
{
    int med = (lo + hi) / 2;
    if (med == nums[med])
        return med;
    if (med > nums[med])
        return findIndexI(nums, lo, med - 1);
    if (med < nums[med])
        return findIndexI(nums, med + 1, hi);
    return -1;
}