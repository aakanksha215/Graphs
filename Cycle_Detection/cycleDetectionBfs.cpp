/***** CYCLE DETECTION IN UNDIRECTED GRAPH *****/
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool checkCycleBfs(int n, unordered_map<int, list<int>> &mp, vector<int> &visited)
{

    queue<pair<int, int>> q;
    visited[n] = 1;
    q.push({n, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : mp[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
            else if (parent != it)
            {
                return true;
            }
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

    for (int i = 1; i < nodes + 1; i++)
    {
        if (!visited[i])
        {
            if (checkCycleBfs(i, mp, visited))
            {
                flag = true;
            }
        }
    }

    if (flag)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    return 0;
}
