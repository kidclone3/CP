#include <bits/stdc++.h>
using namespace std;



int main() {
    // ý tưởng dùng map đã chết. Chúng ta sẽ dùng nén số.
    int m, n;
    cin >> m >> n;
    vector<int> p(m), vt(m, 0);
    for(int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        for(int j = 0; j < m; ++j) {
            if (l <= p[j] && p[j] <= r)
                {
                    if ((p[j] - l) & 1) {
                        vt[j] -= k;
                    }
                    else {
                        vt[j] += k;
                    }
                }

        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << vt[i] << "\n";
    }
}