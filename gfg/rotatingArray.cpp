
#include <bits/stdc++.h>
using namespace std;
void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], i;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}


void rotate(int arr[], int n)
{
    int i = 0;
    int k = 1;
    int j = n - 1;
    int t = n - 1;
    while (i <= j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    while (k <= t)
    {
        swap(arr[k], arr[t]);
        k++;
        t--;
    }
}