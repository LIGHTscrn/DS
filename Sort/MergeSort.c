#include <stdio.h>

void merge(int A[], int lb, int mid, int ub) {
    int i = lb, j = mid + 1, k = lb;
    int B[ub + 1];

    while (i <= mid && j <= ub) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= ub) {
        B[k] = A[j];
        j++;
        k++;
    }

    for (k = lb; k <= ub; k++) {
        A[k] = B[k];
    }
}

void mergeSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(A, lb, mid);       
        mergeSort(A, mid + 1, ub);   
        merge(A, lb, mid, ub);       
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int A[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    mergeSort(A, 0, n - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}
