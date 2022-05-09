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

//Time Complexity : Without priority queue (minheap) = O(n^2) , 
//                  With minheap = O(nlogn + n + e)
void PrimsMST(vector<pair<int, int>> adj[], int n)
{

    vector<int> edgeWeight(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<int> mstSet(n+1, 0);

    //let start node = 1; //or 0 if 0 indexed.
    edgeWeight[1] = 0;

    //min heap to get minimum weight edge.
    //stores pair of <edge_weight, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    //push node 1 and its weight=0 in minHeap.
    minHeap.push({0, 1});

    //Iterate for n-1 times as we will have n-1 edges in MST.
    for(int count=0; count<n-1; count++)
    {
        int currentNode = minHeap.top().second;
        minHeap.pop();

        //Inlcude this min weight node in MST.
        mstSet[currentNode] = 1;

        for(auto neighbor : adj[currentNode])
        {
            
            int adjNode = neighbor.first;
            int adjNodeWeight = neighbor.second;
            //If adj node is not already in MST & its edge weight is better
            if(mstSet[adjNode] == 0 && adjNodeWeight < edgeWeight[adjNode])
            {
                edgeWeight[adjNode] = adjNodeWeight;
                parent[adjNode] = currentNode;
                minHeap.push({edgeWeight[adjNode], adjNode});
            }
        }
    }

    //start node is 1
    for(int i=1; i<parent.size(); i++)
    {
        cout << "parent of " << i << " : " << parent[i] << endl;
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
    PrimsMST(adj, n);

    return 0;
}