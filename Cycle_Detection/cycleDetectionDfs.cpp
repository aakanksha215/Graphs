#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

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

    return 0;
}