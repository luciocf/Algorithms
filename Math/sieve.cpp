// Sieve of Erathostenes
// O(n log log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7+10;

int n;
bool mark[MAXN];

void sieve(void)
{
    for (int i = 2; i*i <= n; i++)
        if (!mark[i])
            for (int j = i*i; j <= n; j+=i)
                mark[j] = 1;
}
