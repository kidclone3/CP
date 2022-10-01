#include<bits/stdc++.h>
using namespace std;
int main() {
    // check if all digits are different.
    int x = 123;
    int used = (x < 1000); // for zero.
    while (x) {
        used |= 1<<(x%10);
        x /= 10;
    }
    cout << (used == (1<<4)-1);
}
