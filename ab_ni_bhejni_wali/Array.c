// Find the maximum and minimum

#include <stdio.h>
void main()
{

    int a[10], min, max, n, i;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Enter the number:");
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        min = a[0];
        max = a[0];
        for (i = 0; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
            }
            if (a[i] > max)
            {
                max = a[i];
            }
        }
        printf("Smallest value is  %d \n ", min);
        printf("Largest value is %d \n ", max);
    }
}