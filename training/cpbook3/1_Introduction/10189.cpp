#include <bits/stdc++.h>
using namespace std;
int n, m;

const int N = 100+5;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    int idx = 1;
    
    while(true) {
        vector<string> a(N, string(N, '.'));
        cin >> n >> m;
        if (n == m && n == 0) break;
        if (idx > 1) cout << "\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == '.') {
                    int cnt = 0;
                    for (int z = 0; z < 8; z++)
                    {
                        int x = i + dx[z];
                        int y = j + dy[z];
                        if (a[x][y] == '*') cnt++;
                    }
                    a[i][j] = '0' + cnt;
                }
            }      
        }
        cout << "Field #" << idx <<":\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[i][j];
            }
            cout << "\n";
        }
        // cout << "\n";
        idx++;
    }
}