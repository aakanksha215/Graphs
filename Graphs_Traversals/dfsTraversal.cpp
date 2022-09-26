#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int n, vector<int> &visited, unordered_map<int, list<int>> &mp, vector<int> &storeDfs)
{
    storeDfs.push_back(n);
    visited[n] = 1;
    for (auto it : mp[n])
    {
        if (!visited[it])
        {
            dfs(it, visited, mp, storeDfs);
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    unordered_map<int, list<int>> mp;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    for (auto x : mp)
    {
        cout << x.first << "->";
        for (auto y : x.second)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    vector<int> storeDfs;
    vector<int> visited(nodes + 1, 0);

    for (int i = 1; i < nodes + 1; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, mp, storeDfs);
        }
    }

    for (int i = 0; i < storeDfs.size(); i++)
    {
        cout << storeDfs[i] << " ";
    }

    return 0;
}