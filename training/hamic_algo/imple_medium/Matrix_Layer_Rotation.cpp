#include <bits/stdc++.h>
using namespace std;
#define ll long long

void matrixRotation(vector<vector<int>> matrix, int r) {
    int n, m;
    n = matrix.size();
    m = matrix[0].size();
    for (int i = 0; i < min(n, m) / 2; i++)
    {
        // With each round, we need find 
        // how many times we have to rotate (anti-clockwise direction)
        int rr = r % (2*(m+n) - 8 * i - 4);
        while(rr--) {
            int tmp = matrix[i][i];
            // Pick the [i][i] to outside.
            // first, we need to direct the top row
            for(int y = i; y < m-i-1; ++y) {
                matrix[i][y] = matrix[i][y+1];
            }
            // second, we direct the right col.
            for(int x = i; x < n-i-1; ++x) {
                matrix[x][m-i-1] = matrix[x+1][m-i-1];
            }
            // third, we direct the bot row
            for(int y = m-i-1; y > i; --y) {
                matrix[n-i-1][y] = matrix[n-i-1][y-1];
            }
            // fourth, we direct the left col
            for(int x = n-i-1; x > i; --x) {
                matrix[x][i] = matrix[x-1][i];
                if (x == i+1) {
                    // add tmp from outside to matrix.
                    matrix[x][i] = tmp;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
     
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> a(n, vector<int>(m));
    for (int  i = 0; i < n; i++)
    {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    matrixRotation(a, r);
    

}