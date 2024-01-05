#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n){

    int i = 0, j = 0, h = n - 1;
    while (j <= h)
    {
        if (a[j] == 1)
        {
            j++;
        }
        else if (a[j] == 2)
        {
            swap(a[h], a[j]);
            h--;
        }
        else if (a[j] == 0)
        {
            swap(a[i], a[j]);
            j++;
            i++;
        }
    }
}