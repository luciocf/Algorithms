// Trie
// Add: O(n)
// Find: O(n)

#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    Node *b[26];
    bool fim = false;
};

Node *root;

void add(Node *node, string const& s)
{
    Node *at = node;

    for (char a: s)
    {
        if (!at->b[a-'a'])
            at->b[a-'a'] = new Node;
        at = at->b[a-'a'];
    }

    at->fim = true;
}

bool find(Node *node, string const& s)
{
    Node *at = node;

    for (char a: s)
    {
        if (!at->b[a-'a'])
            return false;
        at = at->b[a-'a'];
    }

    return at->fim;
}
