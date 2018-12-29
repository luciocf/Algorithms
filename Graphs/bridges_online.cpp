// Bridges Online

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+10;

int dsu_cc[maxn], dsu_2cc[maxn], sz[maxn], pai[maxn], n;

int last_it[maxn], it, bridges;

void init(void)
{
	for (int i = 1; i <= n; i++)
	{
		dsu_cc[i] = dsu_2cc[i] = i;
		sz[i] = 1, pai[i] = -1;
	}
}

int find_2cc(int x)
{
	if (dsu_2cc[x] == x) return x;
	return dsu_2cc[x] = find_2cc(dsu_2cc[x]);
}

int find_cc(int x)
{
	x = find_2cc(x);
	if (dsu_cc[x] == x) return x;
	return dsu_cc[x] = find_cc(dsu_cc[x]);
}

void make_root(int a)
{
	int root = a, ant = -1;

	while (a != -1)
	{
		int p = (pai[a] == -1 ? -1 : find_2cc(pai[a]));

		pai[a] = ant, dsu_cc[a] = root;

		ant = a, a = p;
	}
}

void join_path(int a, int b)
{
	it++;

	int lca = -1;
	vector<int> path_a, path_b;

	while (lca == -1)
	{
		if (a != -1)
		{
			a = find_2cc(a);
			path_a.push_back(a);

			if (last_it[a] == it) lca = a;

			last_it[a] = it;
			a = pai[a];
		}
		if (b != -1)
		{
			b = find_2cc(b);
			path_b.push_back(b);

			if (last_it[b] == it) lca = b;

			last_it[b] = it;
			b = pai[b];
		}
	}

	for (auto v: path_a)
	{
		dsu_2cc[v] = lca;
		if (v == lca) break;
		bridges--;
	}

	for (auto v: path_b)
	{
		dsu_2cc[v] = lca;
		if (v == lca) break;
		bridges--;
	}
}

void add(int a, int b)
{
	a = find_2cc(a), b = find_2cc(b);
	if (a == b) return;

	int ca = find_cc(a), cb = find_cc(b);

	if (ca == cb) join_path(a, b);
	else
	{
		bridges++;

		if (sz[ca] > sz[cb])
		{
			swap(a, b);
			swap(ca, cb);
		}

		make_root(a);
		pai[a] = b, dsu_cc[a] = find_cc(b);
		sz[cb] += sz[ca];
	}
}
