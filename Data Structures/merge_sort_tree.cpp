// Merge Sort Tree
// Query: O(log²n)

// Example problem: Amount of numbers greater than k in [l...r]

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int num[maxn];

vector<int> tree[4*maxn];

void build(int node, int l, int r)
{
	if (l == r)
	{
		tree[node].push_back(num[l]);
		return;
	}

	int mid = (l+r)>>1;

	build(2*node, l, mid); build(2*node+1, mid+1, r);

	int a = 2*node, b = 2*node+1;
	merge(tree[a].begin(), tree[a].end(), tree[b].begin(), tree[b].end(), back_inserter(tree[node]));
}

int query(int node, int l, int r, int a, int b, int k)
{
	if (l > b || r < a) return 0;

	if (l >= a && r <= b) 
		return tree[node].end()-lower_bound(tree[node].begin(), tree[node].end(), k);

	int mid = (l+r)>>1;

	return (query(2*node, l, mid, a, b, k)+query(2*node+1, mid+1, r, a, b, k));
}
