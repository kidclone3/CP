// #include <cassert>
#include <bits/stdc++.h>
// #include <array>
// #include <iostream>
// #include <vector>
// #include <pair>
using namespace std;

// Binary Trie
// Based on https://judge.yosupo.jp/submission/72657
// Supports:
// - get min / max / kth element
// - given K, find x: x^K is min / max / kth
//
// Notes:
// - high mem usage. If just need kth_element
//   -> use OrderedSet.h if MAX_VALUE is ~10^6
//   -> use STL/order_statistic.cpp if MAX_VALUE is big / custom type
//
// Tested:
// - (insert, remove, min xor) https://judge.yosupo.jp/problem/set_xor_min
// - (insert, max xor) https://cses.fi/problemset/task/1655/
template<
    class Val = long long,   // values stored in Trie
    class Count = long long, // frequency of values
    int B = (sizeof(Val) * 8 - 2)  // max number of bit
> struct BinaryTrie {
    struct Node {
        std::array<int, 2> child;
        Count count;
        Node() : child{-1, -1}, count(0) {}
    };

    BinaryTrie() : nodes{Node()} {} // create root node

    // Number of elements in the trie
    Count size() {
        return nodes[0].count;
    }

    void insert(Val x, Count cnt = 1) {
        update(x, cnt);
    }
    void remove(Val x, Count cnt = 1) {
        update(x, -cnt);
    }

    // return X: X ^ xor_val is minimum
    pair<Val, Node> min_element(Val xor_val = 0) {
        //assert(0 < size());
        return kth_element(0, xor_val);
    }

    // return X: X ^ xor_val is maximum
    pair<Val, Node> max_element(Val xor_val = 0) {
        //assert(0 < size());
        return kth_element(size() - 1, xor_val);
    }

    // return X: X ^ xor_val is K-th (0 <= K < size())
    pair<Val, Node> kth_element(Count k, Val xor_val = 0) {
        //assert(0 <= k && k < size());
        int u = 0;
        Val x = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = get_bit(xor_val, i);
            int v0 = get_child(u, b);
            if (nodes[v0].count <= k) {
                k -= nodes[v0].count;
                u = get_child(u, 1-b);
                x |= 1LL << i;
            } else {
                u = v0;
            }
        }
        return {x, nodes[u]};
    }

    // return frequency of x
    Count count(Val x) {
        int u = 0;
        for (int i = B - 1; i >= 0; i--) {
            int b = get_bit(x, i);
            if (nodes[u].child[b] == -1) {
                return 0;
            }
            u = get_child(u, b);
        }
        return nodes[u].count;
    }

// private:
    vector<Node> nodes;

    int get_child(int p, int b) {
        //assert(0 <= p && p < (int) nodes.size());
        //assert(0 <= b && b < 2);
        if (nodes[p].child[b] == -1) {
            nodes[p].child[b] = nodes.size();
            nodes.push_back(Node{});
        }
        return nodes[p].child[b];
    }

    void update(Val x, Count cnt) {
        int u = 0;
        for (int i = B - 1; i >= 0; i--) {
            nodes[u].count += cnt;
            //assert(nodes[u].count >= 0);  // prevent over delete
            int b = get_bit(x, i);
            u = get_child(u, b);
        }
        nodes[u].count += cnt;
        //assert(nodes[u].count >= 0);  // prevent over delete
    }

    inline int get_bit(Val v, int bit) {
        return (v >> bit) & 1;
    }
};
int main() {
    int n; cin >> n;
    vector<long long> a(n);
    BinaryTrie<long long, long long> bt;
    bt.insert(0);
    long long preXor = 0LL;
    long long res = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        preXor ^= a[i];
        bt.insert(preXor);
        res = max(res, bt.max_element(preXor).first);
    }
    cout << res;
    // long long xor_sum = 0LL;
    // for(int i = 0 ; i < n; ++i) {
    //     xor_sum ^= a[i];
    //     auto tmp = bt.max_element(xor_sum);
    //     mx.push_back(tmp.first);
    //     
    // }
    // mx.push_back(bt.max_element().first);
    // auto ans = bt.max_element(); 
    // cout << ans.first;
    // for(auto &it: mx) cout << it << " ";
    // cout << *max_element(begin(mx), end(mx));
}
