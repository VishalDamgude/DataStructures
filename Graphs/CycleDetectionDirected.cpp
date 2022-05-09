#include <iostream>
#include <vector>

using namespace std;

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

//Using DFS
bool checkCycleDfs(int currentNode, vector<int> adj[], int *visited, int *dfsVisited) {
    visited[currentNode] = 1;
    dfsVisited[currentNode] = 1;

    for(auto &neighbor : adj[currentNode])
    {
        if(visited[neighbor] == 0)
        {
            if(checkCycleDfs(neighbor, adj, visited, dfsVisited))
            {
                return true;
            }
        } 
        else if(dfsVisited[neighbor] == 1) {
            //when neighbor is marked visited in both visited and dfsVisited arrays, cycle is there.
            return true;
        }
    }
    dfsVisited[currentNode] = 0;

    return false;
}

//Detect cycle in a directed graph
bool DetectCycle(vector<int> adj[], int n)
{
    int visited[n+1] = {0};
    int dfsVisited[n+1] = {0};

    for(int i=1; i<=n; i++)
    {
        if(visited[i] != 1)
        {
            if(checkCycleDfs(i, adj, visited, dfsVisited))
                return true;
        }
    }

    return false;

}


int main() {
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

    //int n = 11;
    int n = 9;
    vector<int> adj[n + 1] = {{}, {2}, {3,6}, {4}, {5}, {}, {5}, {2,8}, {9}, {7}};
    //vector<int> adj[n + 1] = {{}, {2}, {1, 4}, {5}, {2}, {3, 6, 10}, {5, 7}, {6, 8}, {7, 9, 11}, {8, 10}, {5, 9}, {8}};
    Display(adj, n);
    cout << DetectCycle(adj, n) << endl;;

    return 0;
}