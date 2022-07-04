#include <stdio.h>

int linearSearch(int ar[], int n, int x);
int binarySearch(int ar[], int n, int x);

int main()
{
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    int ar[100];
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
    int x;
    printf("Enter the element to be searched\n");
    scanf("%d", &x);

    // printf("Given element is present at position: %d\n", linearSearch(ar, n, x));
    printf("Given element is present at position: %d\n", binarySearch(ar, n, x) + 1);

    return 0;
}

// Linear or Sequential search
// Time complexity- O(n)
int linearSearch(int ar[], int n, int x)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (ar[i] == x)
            break;
    }
    if (i == n)
    {
        printf("No such element found\n");
        return -1;
    }
    else
        return i + 1;
}

// Binary search
// WARNING- Valid only for a sorted array
// Time complexity- O(log n)
int binarySearch(int ar[], int n, int x)
{
    int low = 0, high = n - 1;
    int mid = (low + high) / 2;
    if (ar[mid] == x)
        return mid;
    else
    {
        // Keep searching until low <= high
        while ((high - low) >= 1)
        {
            if (x < ar[mid])
            {
                high = mid - 1;
                mid = (high + low) / 2;
                if (ar[mid] == x)
                    return mid;
            }
            else
            {
                low = mid + 1;
                mid = (high + low) / 2;
                if (ar[mid] == x)
                    return mid;
            }
        }
    }
    return -1;
}

// #include <stdio.h>
// #include <stdlib.h>

// // Both the Binary search functions will only work if the given array is sorted.
// int binarySearchI(int *ar, int n, int x);
// int binarySearchR(int *ar, int l, int r, int n, int x);

// int main()
// {
//     int n;
//     printf("Enter the number of elements in the array\n");
//     scanf("%d", &n);
//     int *ar = (int *)malloc(n * sizeof(int));
//     printf("Enter the elements of the array (Warning: Sorted elements only)\n");
//     for (int i = 0; i < n; i++)
//         scanf("%d", &ar[i]);
//     int x;
//     printf("Enter the element to be searched\n");
//     scanf("%d", &x);

//     printf("Element %d is on the %d position.\n", x, binarySearchI(ar, n, x) + 1);
//     printf("Element %d is on the %d position\n", x, binarySearchR(ar, 0, n - 1, n, x) + 1);

//     return 0;
// }

// int binarySearchI(int *ar, int n, int x)
// {
//     int l, r, mid;
//     l = 0;
//     r = n - 1;
//     mid = (l + r) / 2;
//     if (ar[mid] == x)
//         return mid;
//     else
//     {
//         while ((r - l) >= 1)
//         {
//             if (x < ar[mid])
//             {
//                 r = mid - 1;
//                 mid = (l + r) / 2;
//                 if (ar[mid] == x)
//                     return mid;
//             }
//             else
//             {
//                 l = mid + 1;
//                 mid = (l + r) / 2;
//                 if (ar[mid] == x)
//                     return mid;
//             }
//         }
//     }
//     return -1;
// }

// int binarySearchR(int *ar, int l, int r, int n, int x)
// {
//     int mid = (l + r) / 2;
//     if (ar[mid] == x)
//         return mid;
//     else
//     {
//         if (x < ar[mid])
//         {
//             return binarySearchR(ar, 0, mid - 1, n, x);
//         }
//         else
//         {
//             return binarySearchR(ar, mid + 1, n - 1, n, x);
//         }
//     }
//     return -1;
// }