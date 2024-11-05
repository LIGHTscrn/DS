#include <stdio.h>
void swap(int A[], int i, int j) {
int temp = A[i];
A[i] = A[j];
A[j] = temp;
}
int Partition(int A[], int lb, int ub) {
int Pivot = A[lb];
int Start = lb;
int End = ub;
while (Start < End) {
while (A[Start] <= Pivot && Start < ub)
Start++;
while (A[End] > Pivot)
End--;
if (Start < End)
swap(A, Start, End);
}
swap(A, lb, End);
return End;
}
void Quicksort(int A[], int lb, int ub) {
if (lb < ub) {
int Loc = Partition(A, lb, ub);
Quicksort(A, lb, Loc - 1); 
Quicksort(A, Loc + 1, ub); 
}
}
int main() {
int n, i;
printf("Enter number of elements: ");
scanf("%d", &n);
int A[n];
printf("Enter elements: ");
for (i = 0; i < n; i++) {
scanf("%d", &A[i]);
}
Quicksort(A, 0, n - 1);
printf("\nSorted array: ");
for (i = 0; i < n; i++) {
printf("%d ", A[i]);
}
return 0;
}