#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


/*

    1. Find Bridges
    2. TODO: Find Articulation Points - A vertex which when removed along with its associated edges, 
                increses the number of connected components in graph is called articulation point.
                
        if lowestDiscoveryTime[neighbor] >= discoveryTime[currentNode]
        {
            if currentNode is not a root node || no. of children(currentNode) > 1
            {
                "s is an articulation point."
            }
        }

*/

void DFS(int currentNode, int parent, vector<int> &visited, vector<int> adj[], int& nextTimer,
         vector<int> &discoveryTime, vector<int> &lowestDiscoveryTime)
{
    visited[currentNode] = 1;
    discoveryTime[currentNode] = nextTimer;             //depth of currentNode in DFSTree
    lowestDiscoveryTime[currentNode] = nextTimer;    //lowestDiscoveryTime stores the lowest time of discovery wrt adjancent nodes.
    
    nextTimer++;

    for (int neighbor : adj[currentNode])
    {
        if(neighbor == parent)
            continue;

        if (visited[neighbor] != 1)
        {
            DFS(neighbor, currentNode, visited, adj, nextTimer, discoveryTime, lowestDiscoveryTime);

            /*
                While backtracking from dfs, get the minimum value of lowestDiscoveryTime to discover this node
                from all its neighbors except parent.

            */
            lowestDiscoveryTime[currentNode] = min(lowestDiscoveryTime[currentNode], lowestDiscoveryTime[neighbor]);

            // If neighbor's calculated lowestDiscoveryTime to discover is more that the parent / currentNode's discoveryTime
            // The neighbor can be disconnected from the its parent and the edge from parent to neighbor will be a bridge.
            // If lowestDiscoveryTime is greater than that of parent, there is no way to discover this neighbor from other nodes.
            if(lowestDiscoveryTime[neighbor] > discoveryTime[currentNode])
            {
                cout << "found bridge from " << currentNode << " to " << neighbor << endl;
            }
        }
        else{
            // If neighbor is already visited, then update currentNode's lowestDiscoveryTime to minimum between neighbor's discoveryTime and 
            // its lowestDiscoveryTime.
            lowestDiscoveryTime[currentNode] =  min(lowestDiscoveryTime[currentNode], discoveryTime[neighbor]);
        }
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
    // int n = 9;
    // vector<int> adj[n + 1] = {{}, {2}, {1,3,8}, {2,4}, {3,5}, {6,8}, {5,7}, {6}, {2,5}};
    vector<int> adj[n + 1] = {{}, {2}, {1, 4}, {5}, {2}, {3, 6, 10}, {5, 7}, {6, 8}, {7, 9, 11}, {8, 10}, {5, 9}, {8}};
    // vector<int> adj[n + 1] = {{}, {2}, {1, 4}, {5}, {2}, {3,6,10}, {5,7}, {6,11}, {9}, {8,10}, {5,9},{7}};
    // Display(adj, n);

    vector<int> visited(n + 1, 0);
    int nextTimer = 1;

    vector<int> discoveryTime(n + 1, -1);
    vector<int> lowestDiscoveryTime(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] != 1)
        {
            DFS(i, -1, visited, adj, nextTimer, discoveryTime, lowestDiscoveryTime);
        }
    }
    return 0;
}