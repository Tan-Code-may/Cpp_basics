#include<bits/stdc++.h>
using namespace std;
const int N=1e3 +10;
vector<int> g[N];
bool vis[N];

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
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v[n + 1];

//     for (int i = 0; i < m; i++)
//     {
//         int v1, v2;
//         cin >> v1 >> v2;
//         v[v1].push_back(v2);
//         v[v2].push_back(v1);
//     }

//     for (int i = 0; i < n + 1; i++)
//     {
//         cout << i << ": ";
//         for (int j = 0; j < v[i].size(); j++)
//             cout << v[i][j] << " ";
//         cout << "\n";
//     }

//     return 0;
// }

// void dfs(int vertex)
// {
// 	vis[vertex]= true;
// 	cout<<vertex<<" ";
// 	for(int child: g[vertex])
// 	{
// 		if(vis[child])
// 			continue;
// 		dfs(child);
// 	}
// 	// Time complexity- O(n+e)
// }

// // DFS traversal
// int main()
// {
// 	int n,m;
// 	cin>>n>>m;

// 	for(int i=0;i<m;i++)
// 	{
// 		int v1,v2;
// 		cin>>v1>>v2;
// 		g[v1].push_back(v2);
// 		g[v2].push_back(v1);
// 	} 
// 	dfs(1);
// 	return 0;
// }

// FINDING CONNECTED COMPONENTS IN A GRAPH
// vector<vector<int>> cc; // to store connected components
// vector<int> currentcc;

// void dfs(int vertex)
// {
//     vis[vertex] = 1;

//     // Pushing the nodes in a vector where it's cc are present
//     currentcc.push_back(vertex);

//     for (int child : g[vertex])
//     {
//         if (vis[child])
//             continue;
//         dfs(child);
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     // Formation of Adjacency list to store a graph
//     for (int i = 0; i < e; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     // Accessing all the nodes and checking whether they are traversed or not
//     for (int i = 1; i <= n; i++)
//     {
//         if (vis[i])
//             continue;

//         // Clearing the previous vector, storing cc to store new
//         currentcc.clear();

//         // Running dfs for new cc
//         dfs(i);

//         // Pushing the cc in the vector storing connected components
//         cc.push_back(currentcc);
//     }

//     cout << cc.size() << "\n";
//     for (auto currentcc : cc)
//     {
//         for (auto vertex : currentcc)
//             cout << vertex << " ";
//         cout << "\n";
//     }

//     return 0;
// }

// FINDING WHETHER A CYCLE IS PRESENT IN A GRAPH OR NOT
// bool dfs(int vertex, int parent)
// {
//     vis[vertex] = 1;

//     bool loopExists = false;
//     for (int child : g[vertex])
//     {
//         if (vis[child] == 1 && child == parent)
//             continue;
//         if (vis[child])
//             return true;
//         loopExists = dfs(child, vertex);
//     }

//     return loopExists;
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     // Formation of Adjacency list to store a graph
//     for (int i = 0; i < e; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     bool loopExists = false;

//     // Accessing all the nodes and checking whether they are traversed or not
//     for (int i = 1; i <= n; i++)
//     {
//         if (vis[i])
//             continue;
//         if (dfs(i, 0))
//         {
//             loopExists = true;
//             break;
//         }
//     }
//     cout << loopExists << "\n";

//     return 0;
// }

// ACCESSING DEPTH AND HEIHGT OF A NODE IN A TREE USING DFS FOR A TREEE
// Arrays for storing height and depth
int height[N], depth[N]; 

// DFS for a tree
void dfs(int vertex, int parent = 0)
{
    // Default value of parent is 0, if nothing is specified 0 will be the argument
    for (int child : g[vertex])
    {
        if (child == parent)
            continue;

        // Depth for a node is defined before entering that node with the help of it's parent node.
        depth[child] = depth[vertex] + 1;

        dfs(child, vertex);

        // Height of a vertex/parent is defined after exiting that node with the help of the height of it's child with max height.
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{
    int n;
    cin >> n;

    // Formation of Adjacency list to store the tree
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
        cout << depth[i] << " " << height[i] << "\n";
    return 0;
}
