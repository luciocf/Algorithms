// Unbounded Knapsack
// O(n*m)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e2+10;
const int maxm = 1e5+10;

int w[maxn], c[maxn];
int dp[maxm];

void solve(int n, int m)
{
	for (int i = 1; i <= n; i++)
		for (int j = w[i]; j <= m; j++)
			dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
}