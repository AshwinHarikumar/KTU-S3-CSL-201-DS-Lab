#include <stdio.h>

int partition(int A[], int low, int high) {
    int i, j, pivot, temp;
    i = low;
    j = high;
    pivot = low;

    while (i < j) {
        while (A[i] <= A[pivot] && i < high) {
            i++;
        }
        while (A[j] > A[pivot]) {
            j--;
        }
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    
    temp = A[j];
    A[j] = A[pivot];
    A[pivot] = temp;
    return j;
}

void QuickSort(int A[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(A, low, high);
        QuickSort(A, low, j - 1);
        QuickSort(A, j + 1, high);
    }
}

int main() {
    int A[10], n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    QuickSort(A, 0, n - 1);
    
    printf("\nSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    
    return 0;
}

