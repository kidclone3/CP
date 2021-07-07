#include <bits/stdc++.h>
using namespace std;

int pairsOfSongs(std::vector<int> arr, int time)
{
    int n = arr.size();
    int ans = 0;
    vector<int> mod(n);
    for (int i = 0; i < n; i++)
    {
        mod[i] = arr[i] % time;
    }
    sort(mod.begin(), mod.end());
    for (int i = 0; i < n-1; i++)
    {
        auto tmp = equal_range(mod.begin() + i + 1, mod.end(), time-mod[i]);
        ans += tmp.second - tmp.first;
    }
    return ans;
}

int main() {

}