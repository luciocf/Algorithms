// Knapsack Problem
// O(n*s)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+10;
const int MAXW = 1e3+10;

int dp[MAXW], num[MAXN], peso[MAXN], n, s;

void knapsack_0_1(void)
{
	for (int i = 1; i <= n; i++)
		for (int j = s; j >= 1; j--)
			if (peso[i] <= j)
				dp[j] = max(dp[j], num[i]+dp[j-peso[i]]);
}

void knapsack_unbounded(void)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= s; j++)
			if (peso[i] <= j)
				dp[j] = max(dp[j], num[i]+dp[j-peso[i]]);
}
