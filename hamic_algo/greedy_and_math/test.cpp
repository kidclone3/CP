#include <iostream>
#include <algorithm>
int main() {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a+i); // ~ cin >> a[i];
    }
    std::cout << *(a+1);
}
