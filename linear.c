#include<stdio.h>


int main(){
    int n;
    int target;
    int found = -1;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n;i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter value to be searched: ");
    scanf("%d", &target);
    for (int i = 0; i < n;i++){
        if(arr[i] == target){
            found = 1;
            break;
        }
    }
    if(found == 1){
        printf("Element found");
    }
    else{
        printf("Element not found");
    }
}