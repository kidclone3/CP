#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y; cin >> x >> y; 
    for(int i = y; i >= 1; --i) {
        if (i > x && y/i >= 3) {
            cout << i;
            break;
        }
        if (i <=x && y/i - x/i >= 2) {
            cout << i;
            break;
        }
    }
}
