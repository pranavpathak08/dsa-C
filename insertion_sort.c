#include<stdio.h>

int main(){
    int n;
    int temp;
    int j;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n;i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Unsorted Array: ");
    for (int i = 0; i < n;i++){
        printf("%d ", arr[i]);
    }
    for (int i = 1; i < n;i++){
        temp = arr[i];
        j = i - 1;
        while(temp < arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printf("\nSorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}