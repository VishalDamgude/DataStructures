#include <iostream>
#include <vector>
#include <stack>
#include<queue>

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

void TopologicalSortDFS(int currentNode, vector<int> adj[], int * visited, stack<int> &s) {

    visited[currentNode] = 1;

    for(auto &neighbor: adj[currentNode])
    {
        if(visited[neighbor] == 0)
            TopologicalSortDFS(neighbor, adj, visited, s);
    }
    s.push(currentNode);
}

// Applicable only to Directed Acyclic Graph (DAG).
// Time Complexity: O(V+E)
// Space Complexity: 
void TopologicalSort(vector<int> adj[], int n) {
    stack<int> s;
    int visited[n+1] = {0};

    for(int i=1; i<=n; i++)
    {
        if(visited[i] == 0)
            TopologicalSortDFS(i, adj, visited, s);
    }

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

}

//Kahn's algorithm
void TopologicalSortBFS(vector<int> adj[], int n)
{
    vector<int> indegree(n+1, 0);
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        //cout << indegree[i] << " ";
        for(int &neighbor : adj[i])
        {
            indegree[neighbor]++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for(int &neighbor : adj[currentNode])
        {
            //cout << "indegree of neighbor " << neighbor << " is " << indegree[neighbor] << endl;
            indegree[neighbor]--;
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
        //printf("\n queue front is %d\n", q.front());
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
    //TopologicalSort(adj, n);
    int n=6;
    vector<int> adj[n + 1] = {{}, {}, {}, {4}, {2}, {1,2}, {1,3}};
    Display(adj, n);
    TopologicalSortBFS(adj, n);

    return 0;
}