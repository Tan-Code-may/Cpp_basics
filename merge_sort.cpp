#include<bits/stdc++.h>
using namespace std;

void merge(int ar[],int l,int mid,int r);
void mergeSort(int ar[],int l,int r);

int main()
{
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);

    int *ar = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &ar[i]);

    //bubbleSort(ar, n);
    // selectionSort(ar, n);
    mergeSort(ar, 0, n-1);
    // insertionSort(ar);
    // quickSort(ar);

    printf("Sorted Array-\n");
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");

    return 0;
}

void merge(int ar[],int l,int mid,int r)
{
	int n1=mid-l+1,n2=r-mid;
	int a[n1], b[n2];

	for(int i=0;i<n1;i++)
		a[i]=ar[l+i];

	for(int i=0;i<n2;i++)
		b[i]=ar[mid+1+i];

	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
			ar[k++]=a[i++];
		else
			ar[k++]=b[j++];
	}

	while(i<n1)
		ar[k++]=a[i++];
	while(j<n2)
		ar[k++]=b[j++];
	
}

void mergeSort(int ar[],int l,int r)
{
	if(l==r)
		return;
	int mid=(l+r)/2;
	mergeSort(ar,l,mid);
	mergeSort(ar,mid+1,r);
	merge(ar,l,mid,r);
}
