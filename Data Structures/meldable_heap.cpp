// Meldable Heap
// Insert, Pop and Min/Max in O(log n)

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int v;
	node *l, *r;

	node(int vv)
	{
		v = vv;
		l = NULL, r = NULL;
	}
};

typedef node*& node_t;

node* merge(node *t1, node *t2)
{
	if (!t1 || !t2) return (t1 ? t1 : t2);

	if (t1->v > t2->v) swap(t1, t2);

	if (rand()&1) swap(t1->l, t1->r);

	t1->l = merge(t1->l, t2);

	return t1;
}

void insert(node_t t, int v)
{
	node *aux = new node(v);

	t = merge(t, aux);
}

void pop(node_t t)
{
	t = merge(t->l, t->r);
}

int min(node *t)
{
	return t->v;
}
