#include<iostream>
#include "../Queue/Queue.h"
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

/*

template <typename TwoD>
void myFunction(TwoD& myArray){
     myArray[x][y] = 5;
     etc...
}

// call with
double anArray[10][10];
myFunction(anArray);
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
    //Adjacency matrix
    int A[6][6] = { {0,1,1,0,0,0},
                    {1,0,0,1,0,0},
                    {1,0,0,1,0,0},
                    {0,1,1,0,1,1},
                    {0,0,0,1,0,0},
                    {0,0,0,0,0,1}
    };
    int n, m;
    cin >> n >> m;
    int adj[n+1][n+1];
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=1; i<=n; i++)
    {
        cout << "vertex " << i << " Edges: ";
        for(int j=1; j<=n; j++)
        {
            if(adj[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    BFS(A, 2);
    DFS(A, 4, 6);
    cout << endl;
    return 0;
}