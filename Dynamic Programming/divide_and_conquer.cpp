// DP Optimization - Divide and Conquer
// O(nm log m)

// DPs of the form dp[i][j] = min(dp[i-1][k] + C(k, j)) (k <= j)
// Can be applied when opt(i, j) <= opt(i, j+1)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;

int opt[maxn][maxn], dp[maxn][maxn];

// Suppose C is a certain cost function
void solve(int i, int l, int r)
{
	if (l > r) return;

	int mid = (l+r)>>1;

	for (int k = opt[i][l-1]; k <= mid && k <= opt[i][r+1]; k++)
		if (dp[i-1][k] + C(k, mid) <= dp[i][mid])
			dp[i][mid] = dp[i-1][k] + C(k, mid), opt[i][mid] = k;

	solve(i, l, mid-1); solve(i, mid+1, r);
}
