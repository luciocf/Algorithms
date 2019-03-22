// Mo's Algorithm
// O((n+q)sqrt(n))

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
const int maxq = 1e5+10;
const int bucket = 320;

struct Query {
	int l, r, bloco, id;
} q[maxq];

int ans[maxn], num[maxn], aux;

// arbitrary functions
void add(int x) {}

void rem(int x) {}

bool comp(Query a, Query b)
{
	if (a.bloco == b.bloco) return a.r < b.r;
	return a.bloco < b.bloco;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < m; i++)
	{
		cin >> q[i].l >> q[i].r;

		q[i].id = i, q[i].bloco = q[i].l/bucket;
	}

	sort(q, q+m, comp);

	int l = 1, r = 1;

	for (int i = 0; i < m; i++)
	{
		int ql = l, qr = r;

		while (r > qr) rem(r--);
		while (r < qr) add(++r);
		while (l > ql) add(--l);
		while (l < ql) rem(l++);

		ans[q[i].id] = aux;
	}
}
