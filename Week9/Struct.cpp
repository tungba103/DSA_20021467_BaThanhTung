#include <bits/stdc++.h>

using namespace std;
// Dung ma tran ke
struct DSKe
{
    vector <vector<int>> Edges;
    vector<bool> visited;
    int n;

    void init(int _n)
    {
        n = _n;
        for (int i=0; i<=n; ++i)
        {
            vector<int> Col;
            for (int i=0; i<=n; ++i)
                Col.push_back(0);
            Edges.push_back(Col);
            visited.push_back(0);
        }
    }

    void pushEdges(int u, int v)
    {
        Edges[u][v] = Edges[v][u] = 1;
    }

    void DFS(int u)
    {
        cout << u << " ";
        visited[u] = 1;
        for (int i=1; i<=n; ++i)
            if (visited[i] == 0 && Edges[u][i] == 1)
                DFS(i);
    }

    void BFS(int st)
    {
        deque<int> dq;
        dq.push_back(st);
        visited[st] = 1;
        while (!dq.empty())
        {
            int u = dq.front();
            cout << u << " ";
            dq.pop_front();
            for (int i=1; i<=n; ++i)
                if (visited[i] == 0 && Edges[u][i] == 1)
                {
                    visited[i] = 1;
                    dq.push_back(i);
                }
        }
    }
};

struct DSCanh
{
    vector <vector<int>> Edges;
    vector<bool> visited;
    int n;

    void init(int _n)
    {
        n = _n;
        for (int i=0; i<=n; ++i)
        {
            vector<int> Col;
            Edges.push_back(Col);
            visited.push_back(0);
        }
    }

    void pushEdges(int u, int v)
    {
        Edges[u].push_back(v);
        Edges[v].push_back(u);
    }

    void DFS(int u)
    {
        cout << u << " ";
        visited[u] = 1;
        for (int i: Edges[u])
            if (visited[i] == 0)
                DFS(i);
    }

    void BFS(int st)
    {
        deque<int> dq;
        dq.push_back(st);
        visited[st] = 1;
        while (!dq.empty())
        {
            int u = dq.front();
            cout << u << " ";
            dq.pop_front();
            for (int i: Edges[u])
                if (visited[i] == 0)
                {
                    visited[i] = 1;
                    dq.push_back(i);
                }
        }
    }
};

