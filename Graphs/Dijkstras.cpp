#include <iostream>
#include <vector>
#include <stack>
#include<queue>

using namespace std;

void Display(vector<pair<int, int>> adj[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "vertex " << i << " Edges: ";
        // for (int j = 0; j < adj[i].size(); j++)
        // {
        //     auto it = adj[i][j];
        //     cout << "node= " << it.first << " weight= " << it.second << " ";
        // }
        auto it = adj[i];
        for(auto itr : it)
        {
            cout << "node= " << itr.first << " weight= " << itr.second << " ";
        }
        cout << endl;
    }
}

// Uses min heap priority queue + BFS
void DijkstrasShortestPath(vector<pair<int, int>> adj[], int n, int src)
{
    vector<int> distance(n+1, INT_MAX);
    //min heap to store pair <distance, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    distance[src] = 0;
    minHeap.push({0, src});

    while (!minHeap.empty())
    {
        int currentDist = minHeap.top().first;
        int currentNode = minHeap.top().second;
        minHeap.pop();
        for(auto neighbor : adj[currentNode])
        {
            if(distance[neighbor.first] > currentDist + neighbor.second)
            {
                distance[neighbor.first] = currentDist + neighbor.second;
                minHeap.push({distance[neighbor.first], neighbor.first});
            }
        }
    }
    

    for(int i=1; i<distance.size(); i++)
    {
        cout << "Node: " << i << " Distance: " << distance[i] << endl;
    }
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
    //vector<int> adj[n + 1] = {{}, {2}, {1, 4}, {5}, {2}, {3, 6, 10}, {5, 7}, {6, 8}, {7, 9, 11}, {8, 10}, {5, 9}, {8}};
   
    //int n = 9;
    //vector<int> adj[n + 1] = {{}, {2}, {3,6}, {4}, {5}, {}, {5}, {2,8}, {9}, {7}};
    int n=5;
    //Undirected weighted graph of 5 vertices.
    vector<pair<int,int>> adj[n + 1] = {{}, {{2,2}, {4,1}}, {{1,2},{3,4},{5,5}}, {{2,4},{5,1},{4,3}}, {{1,1},{3,3}}, {{2,5},{3,1}}};
    Display(adj, n);
    DijkstrasShortestPath(adj, n, 1);

    return 0;
}