#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*

    Graph used in this file:
            1
           / \
          /   \
         /     \
        2       3
        \      /
         \    /
          \  /
           4
          / \
         /   \
        /     \
       5       6
*/

// Breadth First Search
// Time Complexity: O(V+E)
void BFS(vector<int> adj[], int n)
{
    queue<int> q;
    int visited[n+1] = {0};
    int startVertex = 0;
    cout << "BFS Traversal" << endl;
    // To traverse all components of graph loop over all vertices.
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] != 1)
        {
            startVertex = i;
            visited[i] = 1;
            q.push(i);
            // Do BFS starting with i'th vertex.
            while (!q.empty())
            {
                int currentVertex = q.front();
                q.pop();
                cout << currentVertex << " ";
                for (int neighbor : adj[currentVertex])
                {
                    if (visited[neighbor] != 1)
                    {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    cout << endl;
}

void DFSHelper(int currentNode, vector<int>& visited, vector<int> adj[])
{
    cout << currentNode << " ";
    visited[currentNode] = 1;
    for(int neighbor : adj[currentNode])
    {
        if(visited[neighbor] != 1)
            DFSHelper(neighbor, visited, adj);
    }
}
void DFS(vector<int> adj[], int n)
{
    cout << "DFS Traversal: " << endl;
    vector<int> visited(n+1, 0);
    for(int i=1; i<=n; i++)
    {
        if(visited[i] != 1)
        {
            DFSHelper(i, visited, adj);
        }
    }
    cout << endl;
}

void Display(vector<int> adj[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "vertex " << i << " Edges: ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // int n, m;
    // cin >> n >> m;
    // vector<int> adj[n + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }

    int n = 11;
    vector<int> adj[n + 1] = {{}, {2}, {1, 4}, {5}, {2}, {3,6,10}, {5,7}, {6,8}, {7,9, 11},{8,10}, {5,9},{8}};
    Display(adj, n);
    BFS(adj, n);
    DFS(adj, n);
    return 0;
}