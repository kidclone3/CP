#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;
bool check[N];
vector<int> ans;
int n;
void sieve() {
    int tmp = N;
    check[0] = check[1] = 1;
    for(int i = 2; i*i <= tmp; ++i) {
        if (check[i]) continue; 
        for(int j = 2*i; j <= tmp; j+=i) {
            check[j] = 1;
        }
    }
}
vector<int> c = {1, 2, 3, 5, 7, 9};
int gen = 0;
void out() {
    if (!check[gen]) ans.push_back(gen);
}
void dequy(int i) {
    if (i == n) {
        out();
        return;
    }
    for (int j = 0; j < 6; ++j) {
        gen *= 10;
        gen += c[j];
        dequy(i+1);
        gen /= 10;
    }
}
int main() {
    cin >> n;
    if (n == 9) cout << "0\n";
    else {
        sieve();
        dequy(0);
        cout << ans.size() <<"\n";
    }
}
