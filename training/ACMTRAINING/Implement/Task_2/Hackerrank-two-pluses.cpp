
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoPluses' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY grid as parameter.
 */

int twoPluses(vector<string> grid) {
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();

    auto inside1 = [&] (int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 'G';
    };
    auto inside2 = [&] (int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 'g';
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int r = 0;
            // Ban kinh
            if (grid[i][j] == 'B') continue;
            while (inside1(i+r, j) && inside1(i, j+r) && inside1(i-r, j) && inside1(i, j-r)) {
                grid[i+r][j] = grid[i][j+r] = grid[i-r][j] = grid[i][j-r] = 'g';
                for (int x = 0; x < n; ++x) {
                    for(int y = 0; y < n; ++y) {
                        if (grid[x][y] == 'B') continue;
                        int R = 0;
                        while(inside1(x+R, y) && inside1(x,y+R) && inside1(x-R,y) && inside1(x,y-R)) {
                            ans = max(ans, (1 + 4*r) * (1 + 4*R));
                            R++;
                        }
                    }
                }
                r++;
            }
            r = 0;
            while (inside2(i+r, j) && inside2(i, j+r) && inside2(i-r, j) && inside2(i, j-r)) {
                grid[i+r][j] = grid[i][j+r] = grid[i-r][j] = grid[i][j-r] = 'G';
                r++;
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
