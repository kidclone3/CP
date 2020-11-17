#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    auto res = find(nums.begin(), nums.end(), target);
    if (res != nums.end())
        return res - nums.begin();
    else
    {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        int lowerVal = *lower;
        if (lower == nums.end())
            return nums.size();
        if (lower == nums.begin())
            return 0;
        return lower - nums.begin();
    }
}
int main()
{
    vector<int> nums{1, 3, 5, 7};
    int target = 2;
    int result = searchInsert(nums, target);
    cout << result;
}