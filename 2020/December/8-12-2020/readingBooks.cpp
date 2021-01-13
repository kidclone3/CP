#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
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

int a[2*100000+5];
int main()
{
    // Y tuong: sap xep tang dan, 1 nguoi doc tu duoi len, nguoi con lai 
    // doc truoc no' 1 cuon.
    // Cong viec can lam chi la tinh tong thoi gian 1 nguoi doc 1 cuon sach.
    // Sau do, xuat ra max(tong, cuon sach doc max *2)
    // Vi sao?
    // Vi khi 2 nguoi doc theo thu tu nhu the' thi` se ko bao gio bi trung nhau.
    // Neu co trung nhau thi chi la` nguoi thu' 2 phai doi nguoi 1 doc xong cuon dau tien
    // ==> mat 2 * max tg = d.an nho nhat.
    // Con neu ko trung nhau thi tong day la thoi gian nho nhat.
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0; i<n; ++i) {
        cin>>a[i];
    }
    sort(a,a+n);
    ll sum=0;
    for(int i=0; i<n; ++i) {
        sum+=a[i];
    }
    cout<< max(sum, (ll) a[n-1]*2);
}