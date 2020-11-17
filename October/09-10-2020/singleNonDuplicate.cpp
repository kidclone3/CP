#include <bits/stdc++.h>
using namespace std;

int res = -1;
void bs(vector<int> &nums, int lo, int hi);
int singleNonDuplicate(vector<int> &nums);

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums);
}
void bs(vector<int> &nums, int lo, int hi)
{
    if (lo > hi)
        return;
    if (res != -1)
        return;
    int med = (lo + hi) / 2;
    int tmp = nums[med];
    if (med == 0 && nums[med + 1] != tmp)
    {
        res = tmp;
        return;
    }
    else if (med == nums.size() - 1 && nums[med - 1] != tmp)
    {
        res = tmp;
        return;
    }
    else if (nums[med - 1] != tmp && nums[med + 1] != tmp)
    {
        res = tmp;
        return;
    }
    else
    {
        if (med - 1 > -1)
            bs(nums, lo, med - 1);
        if (med + 1 < nums.size())
            bs(nums, med + 1, hi);
    }
}
int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    bs(nums, 0, nums.size() - 1);
    return res;
}