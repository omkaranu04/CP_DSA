#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
const ll BIT = 31;
struct Node
{
    ll cnt;
    struct Node *child[2];
    Node() : cnt(0LL)
    {
        child[0] = NULL;
        child[1] = NULL;
    }
};
struct BitTrie
{
    Node *root;
    BitTrie()
    {
        root = new Node;
    }
    void insert(ll x)
    {
        Node *curr = root;
        for (ll i = BIT; i >= 0; i--)
        {
            ll bit = ((x & (1LL << i)) ? 1 : 0);
            curr->cnt++;
            if (curr->child[bit] == NULL)
                curr->child[bit] = new Node;
            curr = curr->child[bit];
        }
        curr->cnt++;
    }
    void remove(ll x)
    {
        Node *curr = root;
        for (ll i = BIT; i >= 0; i--)
        {
            ll bit = ((x & (1LL << i)) ? 1 : 0);
            curr->cnt--;
            curr = curr->child[bit];
        }
        curr->cnt--;
    }
    ll query(ll x)
    {
        ll ans = 0;
        Node *curr = root;
        for (ll i = BIT; i >= 0; i--)
        {
            ll bit = ((x & (1LL << i)) ? 1 : 0);
            if (curr->child[1 - bit] != NULL && curr->child[1 - bit]->cnt > 0)
            {
                ans = ans | (1LL << i);
                curr = curr->child[1 - bit];
            }
            else
            {
                curr = curr->child[bit];
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll q;
    cin >> q;

    BitTrie trie;
    trie.insert(0LL);

    while (q--)
    {
        char c;
        ll x;
        cin >> c >> x;
        if (c == '+')
            trie.insert(x);
        else if (c == '-')
            trie.remove(x);
        else
            cout << trie.query(x) << endl;
    }

    return 0;
}