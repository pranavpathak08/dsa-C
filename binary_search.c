#include<stdlib.h>
#include<stdio.h>

int main(){
    int arr[10] = {-4, -2, 1, 0, 5, 8, 13, 45, 60, 85};
    int item;
    printf("Enter item you want to search: ");
    scanf("%d", &item);

    int low = 0;
    int high = 9;
    int flag = 0;
    int index = 0;

    while(low<=high){
        int mid = low + (high - low) / 2;
        if(item > arr[mid]){
            low = mid + 1;
        }
        else if(item == arr[mid]){
            flag = 1;
            index = mid;
            break;
        }
        else{
            high = mid - 1;
        }
    }
    if(flag == 1){
        printf("Element Found at index %d", index);
    }
    else
        printf("Element Not Found");
}