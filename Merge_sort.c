#include <stdio.h>

void merge(int A[], int l, int m, int r);
void mergesort(int A[], int l, int r);

void mergesort(int A[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2; 
        mergesort(A, l, mid);      
        mergesort(A, mid + 1, r);  
        merge(A, l, mid, r);       
    }
}

void merge(int A[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[m + 1 + j];
    }

    int i = 0, j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    mergesort(A, 0, n - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
