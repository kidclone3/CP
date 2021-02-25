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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll w, h;
    cin >> w >> h;
    char tax_type, donate;
    cin >> tax_type >> donate;
    double tax;
    switch (tax_type)
    {
    case 'A':
        {
            tax = 0;
            break;
        }
    case 'B':
        {
            tax = 0.1;
            break;
        }
    case 'C':
        {
            tax = 0.2;
            break;
        } 
    case 'D':
        {
            tax = 0.29;
            break;
        }
    case 'E':
        {
            tax = 0.35;
            break;
        }
    }
    double salary = 0;
    if (h>40) {
        salary = w*40 + 2*w*(h-40);
    }
    else {
        salary = w*h;
    }
    salary = salary * (1-tax);
    if (donate == 'y') {
        salary -= 10;
    }
    cout << setprecision(2) << fixed << salary ;
}