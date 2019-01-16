// Treap Build
// O(n)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

struct node
{
	int v, w, sz;
	node *l, *r;

	node(int vv)
	{
		v = vv, w = rand(), sz = 1;
		l = r = NULL;
	}
};

int num[maxn]; // must be sorted

void make_heap(node *t)
{
	if (!t) return;

	node *it = t;

	it = ((t->l && t->l->w > it->w) ? t->l : it);
	it = ((t->r && t->r->w > it->w) ? t->r : it);

	if (it != t)
	{
		swap(t->w, it->w);
		make_heap(it);
	}
}

node* build(int l, int r)
{
	if (l > r) return NULL;

	int mid = (l+r)>>1;

	node *t = new node(num[mid]);

	t->l = build(l, mid-1);
	t->r = build(mid+1, r);

	make_heap(t);

	return t;
}
