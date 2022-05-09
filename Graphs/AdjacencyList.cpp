#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
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
// Space Complexity: Adj list - O(V+E), visited array - O(V), queue - O(V)
void BFS(vector<int> adj[], int n)
{
    queue<int> q;
    int visited[n + 1] = {0};
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

void DFSHelper(int currentNode, vector<int> &visited, vector<int> adj[])
{
    cout << currentNode << " ";
    visited[currentNode] = 1;
    for (int neighbor : adj[currentNode])
    {
        if (visited[neighbor] != 1)
            DFSHelper(neighbor, visited, adj);
    }
}
void DFS(vector<int> adj[], int n)
{
    cout << "DFS Traversal: " << endl;
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] != 1)
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

bool CheckCycleUsingBFS(int currentNode, int prevNode, int *visited, vector<int> adj[])
{
    queue<pair<int, int>> q;
    q.push({currentNode, prevNode});

    while (!q.empty())
    {
        int currentNode = q.front().first;
        int prevNode = q.front().second;

        q.pop();

        visited[currentNode] = 1;

        for (int neighbor : adj[currentNode])
        {
            if (visited[neighbor] != 1)
            {
                q.push({neighbor, currentNode});
            }
            else
            {
                if (neighbor != prevNode)
                {
                    // Since current neighbor/adjacent node is  not same as previous node, it means it has been visited
                    // in some different path. So found a cycle as we are visiting it again.
                    return true;
                }
            }
        }
    }
    return false;
}

bool CheckCycleUsingDFS(int currentNode, int prevNode, int *visited, vector<int> adj[])
{
    visited[currentNode] = 1;
    for (int neighbor : adj[currentNode])
    {
        if (visited[neighbor] != 1)
        {
            if (CheckCycleUsingDFS(neighbor, currentNode, visited, adj) == true)
                return true;
        }
        else
        {
            if (neighbor != prevNode)
                return true;
        }
    }
    return false;
}

bool DetectCycle(vector<int> adj[], int n)
{
    int visited[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        // If any componenet of the graph detects cycle, return true.
        if (visited[i] != 1)
        {
            // if(CheckCycleUsingBFS(i, -1, visited, adj))
            if (CheckCycleUsingDFS(i, -1, visited, adj))
            {
                return true;
            }
        }
    }
    return false;
}

bool checkBipartiteDFS(vector<int> adj[], int currentVertex, int *color) {

    for(auto &neighbor : adj[currentVertex]) {
        if(color[neighbor] == -1) {
            color[neighbor] = 1 - color[currentVertex];
            if( !checkBipartiteDFS(adj, neighbor, color))
                return false;
        }
        else if(color[neighbor] == color[currentVertex])
        {
            return false;
        }
    }
    return true;
}

bool checkBipartiteBFS(vector<int> adj[], int startVertex, int *color) {

    queue<int> q;
    color[startVertex] = 0;
    q.push(startVertex);

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for(int &neighbor : adj[currentNode]) {
            if(color[neighbor] == -1)
            {
                color[neighbor] = !color[currentNode]; // or color[neighbor] = 1 - color[currentNode];
                q.push(neighbor);
            }
            else {
                if(color[neighbor] == color[currentNode])
                    return false;
            }
        }

    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n) {
    int color[n+1];
    memset(color, -1, sizeof(color));
    // for(int i=0; i<=n; i++)
    //   printf("%d ", color[i]);

    for(int i=1; i<=n; i++) {
        if (color[i] == -1)
        {
            //if(!checkBipartiteBFS(adj, i, color))
            color[i] = 0;
            if( !checkBipartiteDFS(adj, i, color))
            {
                return false;
            }      
        }
        
    }

    return true;
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
    //int n = 9;
    //vector<int> adj[n + 1] = {{}, {2}, {1,3,8}, {2,4}, {3,5}, {6,8}, {5,7}, {6}, {2,5}};
    vector<int> adj[n + 1] = {{}, {2}, {1, 4}, {5}, {2}, {3, 6, 10}, {5, 7}, {6, 8}, {7, 9, 11}, {8, 10}, {5, 9}, {8}};
    // vector<int> adj[n + 1] = {{}, {2}, {1, 4}, {5}, {2}, {3,6,10}, {5,7}, {6,11}, {9}, {8,10}, {5,9},{7}};
    Display(adj, n);
    BFS(adj, n);
    DFS(adj, n);
    cout << DetectCycle(adj, n) << endl;
    cout << checkBipartite(adj, n) << endl;
    return 0;
}