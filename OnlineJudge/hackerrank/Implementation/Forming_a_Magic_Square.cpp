#include <bits/stdc++.h>
using namespace std;

int formingMagicSquare(vector<vector<int>> s) {
    vector<int> permu = {1, 2, 3, 4, 6, 7, 8, 9};
    vector<vector<int>> gen(3, vector<int> (3, 0));
    gen[1][1] = 5;
    auto check = [](vector<vector<int>> &gen) {
        int cross1, cross2;
        cross1 = cross2 = 0;
        for(int i = 0; i < 3; ++i) {
            int ans1, ans2;
            ans1 = ans2 = 0;
            for(int j = 0; j < 3; ++j) {
                if (i == j) {
                    cross1 += gen[i][j];
                }
                if (j == 2 - i) {
                    cross2 += gen[i][j];
                }
                ans1 += gen[i][j];
                ans2 += gen[j][i];
            }
            if (ans1 != 15 || ans2 != 15) return false;
        }
        if (cross1 != 15 || cross2 != 15) return false;
        return true;
    };
    int ans = INT_MAX;
    while (next_permutation(permu.begin(), permu.end()))
    {   
        int z = 0;
        for (int i = 0; i < 3; i++) {
            for(int j = 0; j <3; j++) {
                if (!(i == j && i == 1)) {
                    gen[i][j] = permu[z++];
                }
            }
        }
        if (check(gen)) {
            int tmp = 0;
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j) {
                    tmp += abs(s[i][j] - gen[i][j]);
                }
            }
            ans = min(ans, tmp);
        }
    }
    return ans;
}

int main() {
    int n = 3;
    vector<vector<int>> a (3, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    cout << formingMagicSquare(a);
        
}