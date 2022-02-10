#include <iostream>
 
using namespace std;
 
const int N = 2e5;
 
struct Heap {
    int a[N];
    int size;
 
    Heap() { size = 0; }
    int top() { return a[1]; }
    void pop() {
        a[1] = a[size];
        a[size--] = 0;
        down(1);
    }
    void push(int v) {
        a[++size] = v;
        up(size);
    }
 
    void up(int v) {
        if (v == 1) return;
        int p = v / 2;
        if (a[p] < a[v]) {
            swap(a[p], a[v]);
            up(p);
        }
    }
 
    void down(int u) {
        if (u * 2 > size) return;
        int v = u * 2;
        if (a[v + 1] > a[v])
            v += 1;
        if (a[u] < a[v]) {
            swap(a[u], a[v]);
            down(v);
        }
    }
} heap;
 
int ans[N];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    char cmd;
    int i = 0;
    while (i < 13 && cin >> cmd) {
        if (cmd == '+') {
            int v; cin >> v;
            if (heap.size < 15000) heap.push(v);
        } else {
            int v = heap.top();
            while (heap.size && heap.top() == v) heap.pop();
        }
        ++i;
    }
 
    int n = 0;
    for (int v = -1; heap.size; heap.pop()) {
        if (heap.top() != v)
            ans[++n] = (v = heap.top());
    }
 
    cout << n << '\n';
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}
 