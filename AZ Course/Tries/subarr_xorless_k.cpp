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
    ll query(ll x, ll k)
    {
        ll ans = 0;
        Node *curr = root;
        for (ll i = BIT; i >= 0; i--)
        {
            if (curr == NULL)
                break;
            ll bit = ((x & (1LL << i)) ? 1 : 0);
            ll kbit = ((k & (1LL << i)) ? 1 : 0);
            if (bit == kbit)
            {
                if (kbit == 1)
                    if (curr->child[1])
                        ans += curr->child[1]->cnt;
                curr = curr->child[0];
            }
            else
            {
                if (kbit == 1)
                    if (curr->child[0])
                        ans += curr->child[0]->cnt;
                curr = curr->child[1];
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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        BitTrie trie;
        trie.insert(0);
        ll ans = 0, curr = 0;
        for (ll i = 0; i < n; i++)
        {
            curr ^= a[i];
            ans += trie.query(curr, k);
            trie.insert(curr);
        }
        cout << ans << endl;
    }

    return 0;
}