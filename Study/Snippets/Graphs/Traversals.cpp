/*
    Always think about traversals as disjoint connected components of a graph with arbitrarily large n number of nodes.
*/

// DFS
// Template
/*
dfs(v) {
    if(visited[v]) return;

    visited[v] = 1
    // process

    for(auto e: adj[v]) dfs(e)
}
*/

// Code
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // graph represented as an adjacency list
int n;                   // number of vertices

vector<bool> visited;

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
}

void dfsAll()
{
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs(i)
}
*/

// BFS
// Template
/*
// Remember - Only visited nodes are pushed into the queue
bfs(v) {
    if(visited[v]) return;

    queue<int> q;
    visited[v] = 1
    q.push(v);

    while(!q.empty()) {
        int f = q.front(); q.pop();

        // process
        for(auto e: adj[v]) {
            if(visited[e]) continue;

            visited[e] = 1;
            q.push(e);
        }
    }
}
*/

// Code
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // adjacency list representation
int n;                   // number of nodes

vector<bool> visited;

void bfs(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int v = q.front(); q.pop();

        for (int u : adj[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

void bfsAll()
{
    for (int i = 0; i < n; i++)
        if (!visited[i])
            bfs(i);
}
*/
