#include<bits/stdc++.h>
using namespace std;
int main() {
    int x = 5;
    int xx = x;
    int i = 0;
    while (xx)
    {
        xx >>= 1;
        i++;   
    }
    cout << (1 << i) << "\n";
    int y = (x & xx) << 1;
    cout << x << " " << y;
}