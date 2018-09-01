// Persistent Segment Tree
// Update: O(log n)
// Query: O(log n)
// Memory: O(n + m log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
const int MAXM = 1e5+10;

struct Node
{
	int v;
	Node *l, *r;

	Node()
	{
		l = r = NULL;
		v = 0;
	}
};

Node *version[MAXM];
int num[MAXN];

void build(Node *node, int l, int r)
{
	if (l == r)
	{
		node->v = num[l];
		return;
	}

	int mid = (l+r)/2;

	node->l = new Node(), node->r = new Node();
	build(node->l, l, mid), build(node->r, mid+1, r);

	node->v = node->l->v+node->r->v;
}

void upd(Node *prev, Node *node, int l, int r, int pos, int v)
{
	if (l == r)
	{
		node->v = v;
		return;
	}

	int mid = (l+r)/2;

	if (pos <= mid)
	{
		node->r = prev->r;
		if (!node->l) node->l = new Node();

		upd(prev->l, node->l, l, mid, pos, v);
	}
	else
	{
		node->l = prev->l;
		if (!node->r) node->r = new Node();

		upd(prev->r, node->r, mid+1, r, pos, v);
	}

	node->v = node->l->v+node->r->v;
}

int query(Node *node, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return node->v;

	int mid = (tl+tr)/2;

	int p1 = query(node->l, tl, mid, l, r);
	int p2 = query(node->r, mid+1, tr, l, r);

	return (p1+p2);
}
