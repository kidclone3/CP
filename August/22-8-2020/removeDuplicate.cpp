#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    /*set<int> removedDup;
    for (auto it:nums)
        removedDup.insert(it);
    
        nums.clear();
        nums.insert(nums.begin(), removedDup.begin(), removedDup.end());
    return nums.size(); */
    int i = nums.size() - 1;
    while (i > 0)
    {
        if (nums[i] == nums[i - 1])
        {
            nums.erase(nums.begin() + i);
        }
        i--;
    }
    return nums.size();
}
int main()
{
    vector<int> nums = {1, 1};
    int size = removeDuplicates(nums);
    for (auto it : nums)
        cout << it << " ";
    return 0;
}