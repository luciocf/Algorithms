// Mo's Algorithm
// O((n+q)sqrt(n))

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4+10;
const int MAXQ = 5e4+10.

struct Q {
	int l, r, bloco, id;
} q[MAXQ];

int ans[MAXN], num[MAXN];

bool comp(Q a, Q b)
{
	if (a.bloco == b.bloco) return a.r < b.r;
	return a.bloco < b.bloco;
}

int main(void)
{
	int s = sqrt(n)+1;

	for (int i = 1; i <= m; i++)
	{
		cin >> q[i].l >> q[i].r;
		q[i].id = i, q[i].bloco = q[i].l/s;
	}

	int l = 1, r = 1, sum = num[1];

	for (int i = 1; i <= m; i++)
	{
		while (r > q[i].r)
			sum -= num[r--];
		while (r < q[i].r)
			sum += num[++r];
		while (l > q[i].l)
			sum += num[--l];
		while (l < q[i].l)
			sum -= num[l++];

		ans[q[i].id] = sum;
	}
}
