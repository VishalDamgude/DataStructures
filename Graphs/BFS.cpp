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
    BFS(A, 2);
    return 0;
}