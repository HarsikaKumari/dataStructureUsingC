// Binay Search

#include <stdio.h>

void main()
{
    int key, low, high, mid;
    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key element:");
    scanf("%d", &key);

    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == key)
        {
            printf("Element found %d ", mid + 1);
            break;
        }
        if (key < arr[mid])
        {
            high = mid - 1;
        }
        if (key > arr[mid])
        {
            low = mid + 1;
        }
    }
    if (low > high)
    {
        printf("Naikhe");
    }
}