#include <stdio.h>
void main()
{
    int size;
    int val;
    int ub = 0; // upper bound

    printf("Enter the size of the element:");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    // {12,3,4,5,0,0}
    // {5, 12,3,4,5,5}
    //                ^

    while (1)
    {
        if (ub >= size)
        {
            printf("Array is full\n");
            break;
        }

        printf("Enter the value to insert:\n "); // value to insert
        scanf("%d", &val);

        for (int i = ub; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = val;
        ub++; // increment

        printf("Value after insertion:\n ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}