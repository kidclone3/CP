#include <bits/stdc++.h>
using namespace std;
int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int, int>> avail; 
//         first = lastday, second = duration.
        for (auto &it : courses) {
            if (it[0] <= it[1]) {
                avail.push_back({it[1], it[0]});
            }
        }
        if (avail.size() == 0) return 0;
        sort(avail.begin(), avail.end());
        vector<vector<int>> dp (avail.size(), vector<int> (3, 0));
        int ans = 0;
        for (int i = 0; i < avail.size(); ++i) {
            dp[i][0] = 1;
            dp[i][1] = avail[i].second;
            for (int j = 0; j < i; ++j) {
                if (dp[j][1] + avail[i].second <= avail[i].first) {
                    if (dp[i][0] < dp[j][0] + 1) {
                        dp[i][0]++;
                        dp[i][1] = dp[j][1] + avail[i].second;
                    }
                    else if (dp[i][0] == dp[j][0] + 1) {
                        dp[i][1] = min(dp[i][1], dp[j][1] + avail[i].second);
                    }
                }
            }
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }

int main() {
    vector<vector<int>> a = {{100, 200}, {200, 1300}, {1200, 1250}, {2000, 3200}};
    cout << scheduleCourse(a);
}