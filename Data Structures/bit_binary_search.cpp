// Binary Search in BIT (K-th number)
// O(log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
const int MAXL = 20;

int bit[MAXN], n;

int kth(int k)
{
    int soma = 0, ans = 0;
    for (int i = 1<<MAXL; i+ans <= n; i >>= 1)
        if (soma+bit[ans+i] < k)
            soma += bit[ans+i], ans += i;

    return ans+1;
}
