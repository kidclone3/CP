#include<bits/stdc++.h>
using namespace std;

const int N =2 * 1e5+5;
int a[N], pos[N];

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > a[i-1]) pos[i] = i-1;
        else {
            int tmp = i-1;
            while(a[tmp] >= a[i]) tmp = pos[tmp];
            pos[i] = tmp;
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << pos[i] << " ";
    }
}