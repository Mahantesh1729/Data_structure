#include <stdio.h>
#include <stdbool.h>
void sort(int n, int a[]);
bool search(int k, int i, int j, int a[]);
int main()
{
    printf("How many numbers do you want to enter\n");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elments of the array: \n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(n, a);

    printf("Enter the element that you want to search\n");

    int k;

    scanf("%d", &k);

    if(search(k, 0, n, a))
    {
        printf("Element Found\n");
        return 0;
    }
    printf("Element not found\n");
    return 1;
}
void sort(int n, int a[])
{
    int swap = 1, k, j = n;

    while(swap != 0)
    {
        swap = 0;

        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] > a[i + 1])
            {
                k = a[i];

                a[i] = a[i + 1];

                a[i + 1] = k;

                swap++;
            }
        }
    n--;
    }
}
bool search(int k, int i, int j, int a[])
{
    int mid = (i + j) / 2;
    if(i <= j)
    {
        if(k == a[mid])
        {
            return true;
        }
        else if(a[mid] < k)
        {
            return search(k, mid +1, j, a);
        }
        else
        {
            return search(k, i, mid - 1, a);
        }
    }
    return false;
}
