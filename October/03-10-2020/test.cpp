#include <bits/stdc++.h>
using namespace std;
double pi = 3.14159;
bool isPowerOfThree(int n)
{
    if (n <= 0)
        return false;
    float t = log(n) / log(3);
    double r1 = roundf(t * 10000000) / 10000000;
    double r2 = floorf(t);
    return (r2 - r1) == 0;
}

double *getPointerToPi()
{

    double *a = &pi;
    return a;
}
int main()
{
    double *a;
    a = getPointerToPi();
    cout << a;
    //  int x = 4782968;
    //  cout << isPowerOfThree(x);
}
