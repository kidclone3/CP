#include<bits/stdc++.h>
using namespace std;

void swapArray(int a[], int start1, int start2, int d) {
    for(int i = 0; i < d; ++i) {
        swap(a[start1+i], a[start2+i]);
    }
}

void leftRotate1(int a[], int d, int n) {
    // Ham de quy.
    if (d == 0 || d == n) return; // Dieu kien de thoat de quy.
    if (d >= n) {
        d -= n;
    }
    // Neu so luong phan tu can xoay vua bang 1/2 mang 
    if (n-d == d) {
        swapArray(a, 0, n-d, d);
        return;
    }
    // Neu A be hon B.
    if (d < n-d) {
        swapArray(a, 0, n-d, d);
        leftRotate1(a, d, n-d);
    }
    else { // Neu B be hon A.
        swapArray(a, 0, d, n-d);
        leftRotate1(a + n - d, 2 * d - n, d);
    }
}

void leftRotateIterative(int a[], int d, int n) {
    int i, j;
    if (d == 0 || d == n) return;
    if (d > n) d = d % n;
    i = d;
    j = n-d;
    while (i != j) {
        if (i < j) {
            swapArray(a, d-i, d+j-i, i);
            j -= i;
        } else {
            swapArray(a, d-i, d, j);
            i -= j;
        }
    }
    swapArray(a, d-i, d, i);
}

void leftRotate(int arr[], int d, int n)
{
    int i, j;
    if (d == 0 || d == n)
        return;
   
    /* If number of elements to be rotated is more than array size*/
      if(d > n)
      d = d % n;
   
    i = d;
    j = n - d;
    while (i != j)
    {
        if (i < j) /*A is shorter*/
        {
            swapArray(arr, d - i, d + j - i, i);
            j -= i;
        }
        else /*B is shorter*/
        {
            swapArray(arr, d - i, d, j);
            i -= j;
        }
         
        // printArray(arr, 7);
    }
     
    /*Finally, block swap A and B*/
    swapArray(arr, d - i, d, i);
}
 

int main() {
    int a[] = {1,2,3,4,5};
    int n = 5;
    int d = 3;
    leftRotate(a, d, n);
    // leftRotateIterative(a, d, n);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
}
