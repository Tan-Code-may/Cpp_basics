#include<bits/stdc++.h>
using namespace std;

//IMPORTANT POINTS
// 1. A directed graph may be acyclic even after having a circular part. 
// 2. Acyclic undirected graphs are known as trees.
// 3. A stongly connected component is the one in which we can traverse any node from any other node.


// Adjacency Matrix
// int main()
// {
// 	int n,m;
// 	cin>>n>>m;
// 	int graph[n+1][n+1];
// 	memset(graph,0,sizeof(graph));
//
// 	for(int i=0;i<m;i++)
// 	{
// 		int v1,v2;
// 		cin>>v1>>v2;
// 		graph[v1][v2] = 1;
// 		graph[v2][v1] = 1;
// 	} 
//
// 	for(int i=0;i<n+1;i++)
// 	{
// 		for(int j=0;j<n+1;j++)
// 			cout<<graph[i][j]<<" ";
// 		cout<<"\n";
// 	}

// 	return 0;
// }


// Adjacency list
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v[n + 1];

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    for (int i = 0; i < n + 1; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
