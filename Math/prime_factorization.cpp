// Prime Factorization of a number
// Complexidade: O(sqrt n)

#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void get(int n)
{
    for (int i = 2; i*i <= n; i++)
    {
        while (n%i == 0)
        {
            primes.push_back(i);
            n/=i;
        }
    }

    // if n is prime
    if (n >= 2)
        primes.push_back(n);
}
