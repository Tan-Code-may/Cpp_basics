#include <bits/stdc++.h>
using namespace std;

int partition(int *ar, int start, int end);
void quicksort(int *ar, int start, int end);

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    quicksort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
    cout << "\n";

    return 0;
}

int partition(int *ar, int start, int end)
{
    int partind = 0;
    for (int i = 0; i < end; i++)
    {
        if (ar[i] <= ar[end])
        {
            swap(ar[i], ar[partind]);
            partind++;
        }
    }
    swap(ar[partind], ar[end]);
    return partind;
}

void quicksort(int *ar, int start, int end)
{
    if (start < end)
    {
        int pi = partition(ar, start, end);
        quicksort(ar, start, pi - 1);
        quicksort(ar, pi + 1, end);
    }
}