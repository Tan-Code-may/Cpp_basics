#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *ar, int n);
void selectionSort(int *ar, int n);
void insertionSort(int *ar, int n);
void mergeSort(int *ar, int n);
void quickSort(int *ar, int n);

int main()
{
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);

    int *ar = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &ar[i]);

    bubbleSort(ar, n);
    //selectionSort(ar, n);
    // mergeSort(ar);
    // insertionSort(ar);
    // quickSort(ar);

    printf("Sorted Array-\n");
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");

    return 0;
}

void bubbleSort(int *ar, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
            {
                int t = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = t;
            }
        }
}

void selectionSort(int *ar, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[i])
            {
                int t = ar[i];
                ar[i] = ar[j];
                ar[j] = t;
            }
        }
    }
}

void insertionSort(int *ar, int n)
{
    for (int i = 1; i < n; i++)
        for (int j =)
}
