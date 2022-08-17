#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int size[N];

// Disjoint Subset Union (DSU) consists of three functions -
// 1. make: generates new independent nodes.
// 2. find: determines the parent of a given node.
// 3. Union: connects root nodes of two given 'connected components'.

void make(int n) // Intializing each individual element
{
    parent[n] = n;
    size[n] = 1;
}

int find(int n) //Finding the parent of an individual element
{
    if (parent[n] == n)
        return n;
    // Path Compression(optimisation to reduce time complexity)
    return parent[n] = find(parent[n]);
}

void Union(int a, int b) //Joining two different groups
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        // Union by size (another optimisation to reduce time complexity)
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    // Creating 'n' independent nodes
    for (int i = 1; i <= n; i++)
        make(i);

    // Connecting these n components as given in the input
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int connnected_ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            connnected_ct++;
    }

    cout << connnected_ct << "\n";
    return 0;
}
