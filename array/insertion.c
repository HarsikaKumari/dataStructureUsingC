#include<stdio.h>

int main() {
    int pos, value, size;
    printf("Enter the size of the array you want: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the %d values in your array:", size);
    for(int i = 0; i < size; i++){
        printf("arr[%d]", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the position where you want to insert the value in your array:");
    scanf("%d", &pos);

    printf("Enter the value which you want to insert in that position:");
    scanf("%d", &value);

    for(int i = size; i > pos; i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = value;

    printf("The new array after inserting your value is: ");
    for (int i = 0; i <= size; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
