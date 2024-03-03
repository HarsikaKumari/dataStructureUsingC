#include<stdio.h>
int pos, value, size;

int main() {
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

    for(int i = size-1; i > pos-1; i--){
        arr[i-1] = arr[i];
    }
    arr[pos-1] = value;
    size++;

    printf("The new array after inserting your value is: ");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d]", arr[i]);
    }
    
    return 0;
}