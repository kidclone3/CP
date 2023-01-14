
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    int n, m;
    n = matrix.size();
    m = matrix[0].size();
    for (int i = 0; i < min(n, m) / 2; i++)
    {
        // copy vi tri [i][i] ra ngoai truoc.
        // ok, bay gio se rotate theo so' lan?
        int rr = r % (2*(n-i-1) + 2*(m-i-1));
        while(rr--) {
            int tmp = matrix[i][i];
            // First, shift the top row to the left.
            for(int y = i+1; y < m-i; ++y) {
                matrix[i][y-1] = matrix[i][y];
            }
            // Now, shift the right col to the top.
            for(int x = i+1; x < n-i; ++x) {
                matrix[x-1][m-i-1] = matrix[x][m-i-1];
            }
            // Then, shift the bot row to the right.
            for(int y = m-i-2; y >= i; --y) {
                matrix[n-i-1][y+1] = matrix[n-i-1][y];
            }
            // Last, shift the left col to the bot.
            for(int x = n-i-2; x > i; --x) {
                matrix[x+1][i] = matrix[x][i];
            }
            matrix[i+1][i] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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
