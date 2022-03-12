#include<iostream>
#include "../Queue/Queue.h"
#include <vector>
using namespace std;

/*

    Graph used in this file:
            0
           / \
          /   \
         /     \
        1       2
        \      /
         \    /
          \  /
           3
          / \
         /   \
        /     \
       4       5
*/

//Breadth First Search
void BFS(int A[][6], int startVertex)
{
    int n = sizeof(A[0])/sizeof(A[0][0]);
    Queue q(n);
    int visited[n] = {0};
    //visit first node and add to queue.
    cout << startVertex << " ";
    q.Enqueue(startVertex);
    visited[startVertex] = 1;    

    while(!q.IsEmpty())
    {
        int currentVertex = q.Dequeue();
        for(int neighbor=0; neighbor<n; neighbor++)
        {
            //If edge between current vertex and neighbor node and its not visited yet.
            if(A[currentVertex][neighbor] == 1 && visited[neighbor] == 0)
            {
                cout << neighbor << " ";
                visited[neighbor] = 1;
                q.Enqueue(neighbor);
            }
        }
    }
    cout << endl;
}

void DFS(int A[][6], int startVertex, int n)
{
    static int visited[6] = {0};
    cout << startVertex << " ";
    visited[startVertex] = 1;
    for(int neighbor=0; neighbor<n; neighbor++)
    {
        if(A[startVertex][neighbor] == 1 && visited[neighbor] == 0)
        {
            DFS(A, neighbor, n);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        cout << "vertex " << i << " Edges: ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    //BFS(A, 2);
    //DFS(A, 4, 6);
    cout << endl;
    return 0;
}