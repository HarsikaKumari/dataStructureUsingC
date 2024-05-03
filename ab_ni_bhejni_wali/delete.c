#include <stdio.h>
void main()
{
    int arr[50];
    int pos, i, num;
    printf("Enter the number of the elements:");
    scanf("%d", &num);
    printf("Enter the elements in array\n ");
    for (i = 0; i < num; i++)
    {
        printf("arr[%d] ", i);
        scanf("%d", &arr[i]);
    }
    printf("Define the position of the array element where you want to delete:\n ");
    scanf("%d", &pos);
    if (pos >= num + 1)
    {
        printf("Deletion is not possible in the array..!");
    }
    else
    {
        for (i = pos - 1; i < num - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        printf("The resultant array is \n");

        for (i = 0; i < num - 1; i++)
        {
            printf("arr[%d] ", i);
            printf("%d \n", arr[i]);
        }
    }
}