#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int bit[N];

int n; // n is size of array.
void update(int i, int val) {
    for(; i <= n; i += i&(-i)) 
        bit[i] += val;
}

int get(int i) {
    int res = 0;
    for(; i > 0; i -= i&(-i))
        res += bit[i];
    return res;
}

int get(int l, int r) {
    return get(r) - get(l-1);
}

int main() {

}