// Floyd-Warshall
// O(n^3)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

int dist[MAXN][MAXN], n;

int main(void)
{
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}
