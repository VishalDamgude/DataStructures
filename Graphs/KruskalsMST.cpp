#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int u;
        int v;
        int weight;

        Node(int node1, int node2, int wt)
        {
            u = node1;
            v = node2;
            weight = wt;
        }
};

bool comp(Node &a, Node &b)
{
    return a.weight < b.weight;
}


int find(int node, vector<int> &parent)
{
    if(node == parent[node])
        return node;
    
    parent[node] = find(parent[node], parent);
    return parent[node];
}

void unionSet(int u, int v, vector<int>& parent, vector<int> &rank)
{
    int rootOfU = find(u, parent);
    int rootOfV = find(v, parent);

    if(rootOfU != rootOfV)
    {
        if(rank[rootOfU] > rank[rootOfV])
        {
            parent[rootOfV] = rootOfU;
        }
        else if(rank[rootOfU] < rank[rootOfV])
        {
            parent[rootOfU] = rootOfV;
        }
        else{
            parent[rootOfV] = rootOfU;
            rank[rootOfU] += 1;     //when ranks of two roots are same, make one of them as parent of other root node,\
                                    // and increment its rank 
        }
    }
}

int main()
{
    vector<Node> edges;
    edges.push_back(Node(1,2,2));
    edges.push_back(Node(1,4,1));
    edges.push_back(Node(1,5,4));
    edges.push_back(Node(2,3,3));
    edges.push_back(Node(2,4,3));
    edges.push_back(Node(2,6,7));
    edges.push_back(Node(3,4,5));
    edges.push_back(Node(3,6,8));
    edges.push_back(Node(4,5,9));

    sort(edges.begin(), edges.end(), comp);

    for(auto &edge : edges)
    {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }

    int n = edges.size();
    vector<int> parent(n);
    for(int i=0; i<n; i++)
        parent[i] = i;      //initially parent of each node is a node itself
    
    vector<int> rank(n, 0); //initialize rank of each node to 0;

    int cost = 0;
    vector<pair<int, int>> mst;  //mst will store edges from u to v;

    //iterate over sorted edges.
    for(auto &edge : edges)
    {
        if(find(edge.u, parent) != find(edge.v, parent))
        {
            //if u and v are not connected, add then to mst and connect them using unionset.
            cost += edge.weight;
            mst.push_back({edge.u, edge.v});
            unionSet(edge.u, edge.v, parent, rank);
        }
    }

    cout << "cost of MST: " << cost << endl;
    for(auto it : mst)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}