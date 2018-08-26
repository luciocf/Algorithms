// Dijkstra
// O(m log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
const int INF = 1e9+10;

typedef pair<int, int> pii;

int dist[MAXN], n;
bool mark[MAXN];
vector<pii> grafo[MAXN];

void dijkstra(int u)
{
    for (int i = 1; i <= n; i++) dist[i] = INF;

    dist[u] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > fila;
    fila.push({0, u});

    while (!fila.empty())
    {
        int x = fila.top().second;
        fila.pop();

        if (mark[x]) continue;
        
        mark[x] = 1;
        
        for (auto v: grafo[x])
        {
            if (dist[v.second] > dist[x] + v.first)
            {
                dist[v.second] = dist[x] + v.first;
                fila.push({dist[v.second], v.second});
            }
        }
    }
}
