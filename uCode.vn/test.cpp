#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};

int main()
{
<<<<<<< HEAD
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1,5,2,4,3};
    // print(arr);
    // sort(arr.begin(), arr.end());
    // sort(all(arr));
    F_OR(i, 0, arr.size(), 1) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    for (auto it:arr) {
        cout<<it<<" ";
    }
    cout<<"\n";
    print(arr);
}
=======
    int a = 8;
    a = 9;
    cin >> a;
    bool x = 0 & 1;
    cout << x;
    // int b = ceil(pow(a, 0.33333));
    // cout << b;
}
// No chua ra cua so de nhap du lieu :(
// magic :D
// không ctrl C được luôn
// ủ/a sao không nhập được
>>>>>>> 3834b015461c5890a8e1fb2fc84e9b0c349e74bd
