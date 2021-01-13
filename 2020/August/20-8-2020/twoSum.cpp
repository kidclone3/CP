#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> nums, int first, int last, int val)
{
    int mid = (first + last) / 2;
    if (nums[mid] == val)
        return mid;
    if (nums[mid] > val)
        binarySearch(nums, first, mid - 1, val);
    if (nums[mid] < val)
        binarySearch(nums, mid + 1, last, val);

    return -1;
}
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = target - nums[i]; //the second number in the vector
        if (temp != nums[i] && binary_search(nums.begin(), nums.end(), temp))
        {
            res.push_back(i);
            res.push_back(binarySearch(nums, 0, nums.size() - 1, temp));
            break;
        }
    }
    return res;
}

int main()
{
    /*int n;
    vector<int> nums;
    cout << "Input size of vector: ";
    cin >> n;
    cout << "Input the vector: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << "Input target: ";
    int target;
    cin >> target;*/
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> res;
    res = twoSum(nums, target);
    for (auto it : res)
        cout << it << " ";
    return 0;
}