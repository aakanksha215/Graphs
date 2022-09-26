#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> bfsTraversal(unordered_map<int, list<int>> mp, int V)
{
    vector<int> bfs;
    vector<int> visited(V + 1, 0);

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : mp[node])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }
    }

    return bfs;
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

    vector<int> ans;
    ans = bfsTraversal(mp, nodes);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}