// Finding Divisors of a number
// O(sqrt(n))

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7+10;

vector<int> d;

void get(int n)
{
    for (int i = 1; i*i <= n; i++)
    {
        if (n%i) continue;

        if (n/i == i) d.push_back(i);
        else d.puhs_back(i), d.push_back(n/i);
    }
}
