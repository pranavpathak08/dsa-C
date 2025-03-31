#include<stdio.h>


int main(){
    int row, col;
    printf("Enter number of rows");
    scanf("%d", &row);
    printf("Enter number of columns");
    scanf("%d", &col);

    int arr[row][col];
    int ctr = 0;

    for (int i = 0; i < row;i++){
        for (int j = 0; j < col;j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0){
                ctr++;
            }
        }
    }
    for (int i = 0; i < row;i++){
        for (int j = 0; j < col;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


    if(ctr>((row*col)/2)){
        printf("It is sparse Matrix");
    }
    else{
        printf("It is not a sparse matrix");
    }
}


//Row major : (i*rows + j)
//Col major : (j*cols + i)