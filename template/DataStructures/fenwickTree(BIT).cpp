#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int LOGN = log(N) + 1;
int bit[N];
int a[N];
int n; // n is size of array.

void initialize() { // create bit in O(N)
    for(int i = 1 ; i <= n; ++i) {
        bit[i] += a[i];
        if (i + (i&-i) <= n) bit[i+(i&-i)] += bit[i];
    }
}

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

int bit_search(int v) {
    int sum = 0;
    int pos = 0;
    for(int i = LOGN; i >= 0; --i) {
        if (pos + (1<<i) < N && sum + bit[pos + (1<<i)] < v) {
            pos += 1<<i;
            sum += bit[pos];
        }
    }
    return pos + 1; 
    // +1 because 'pos' will have position of largest value less than 'v'
}

int main() {

}