#include <iostream>
using namespace std;

/*****Adjacency Matrix for Undirected Graph ****/

int main()
{
    int nodes, edges;
    cout << "Enter number of nodes and edges";
    cin >> nodes >> edges;

    int adj[nodes + 1][nodes + 1];

    for (int i = 1; i < nodes + 1; i++)
    {
        for (int j = 1; j < nodes + 1; j++)
        {
            adj[i][j] = 0;
        }
        cout << endl;
    }

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 1; i < nodes + 1; i++)
    {
        for (int j = 1; j < nodes + 1; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}