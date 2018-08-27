// Travelling Salesman Problem
// O(2^n * n²)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 17;
const int INF = 1e9+10;

int dp[MAXN][1<<MAXN], dist[MAXN][MAXN], n;

int solve(int pos, int mask)
{
    if (mask == (1<<n)-1) return dist[pos][0];
    if (dp[pos][mask] != -1) return dp[pos][mask];

    int ans = INF;
    for (int i = 0; i < n; i++)
        if (!(mask&(1<<i))) ans = min(ans, dist[pos][i]+solve(i, mask|(1<<i)));
    
    return dp[pos][mask] = ans;
}
