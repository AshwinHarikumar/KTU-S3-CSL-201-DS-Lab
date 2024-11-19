#include <stdio.h>

void Merge(int A[], int low, int mid, int high) {
    int B[10]; // You might want to adjust this size based on input
    int x = low, y = mid + 1, i = low;

    while (x <= mid && y <= high) {
        if (A[x] < A[y]) {
            B[i] = A[x];
            x++;
        } else {
            B[i] = A[y];
            y++;
        }
        i++;
    }

    while (x <= mid) {
        B[i] = A[x];
        x++;
        i++;
    }

    while (y <= high) {
        B[i] = A[y];
        y++;
        i++;
    }

    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
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

    MergeSort(A, 0, n - 1);
    
    printf("\nSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    
    return 0;
}

