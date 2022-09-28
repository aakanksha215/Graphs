#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool checkCycleDfs(int node, int parent, vector<int> &visited, unordered_map<int, list<int>> &mp)
{
    visited[node] = 1;
    for (auto it : mp[node])
    {
        if (!visited[it])
        {
            if (checkCycleDfs(it, node, visited, mp))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int nodes, edges;
    cin >> nodes;
    cin >> edges;

    unordered_map<int, list<int>> mp;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    cout << endl;
    cout << "Adjacency List--->" << endl;
    for (auto x : mp)
    {
        cout << x.first << "->";
        for (auto y : x.second)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> visited(nodes + 1, 0);
    bool flag = false;

    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
        {
            if (checkCycleDfs(i, -1, visited, mp))
            {
                flag = true;
            }
        }
    }
    if (flag == true)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    return 0;
}