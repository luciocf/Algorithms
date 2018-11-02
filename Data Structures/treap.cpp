// Treap

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int v, w, sz;
	node *l, *r;

	node()
	{
		v = 0, sz = 1, w = rand();
		l = r = NULL;
	}
};

typedef node*& node_t;

int sz(node *t)
{
	if (!t) return 0;
	return t->sz;
}

void upd_size(node *t)
{
	if (t) t->sz = sz(t->l)+sz(t->r)+1;
}

bool find(node *t, int x)
{
	if (!t) return false;

	if (t->v == x) return true;
	else if (x > t->v) return find(t->r, x);
	return find(t->l, x);
}

void split(node *t, int x, node_t l, node_t r)
{
	if (!t) l = r = NULL;
	else if (t->v > x) split(t->l, x, l, t->l), r = t;
	else split(t->r, x, t->r, r), l = t;

	upd_size(t);
}

void merge(node_t t, node *l, node *r)
{
	if (!l || !r) t = (l ? l : r);
	else if (l->w > r->w) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;

	upd_size(t);
}

void insert(node_t t, node *it)
{
	if (!t) t = it;
	else if (it->w > t->w) split(t, it->v, it->l, it->r), t = it;
	else insert((it->v > t->v ? t->r : t->l), it);

	upd_size(t);
}

void erase(node_t t, int x)
{
	if (t->v == x) merge(t, t->l, t->r);
	else erase((x > t->v ? t->r : t->l), x);

	upd_size(t);
}
