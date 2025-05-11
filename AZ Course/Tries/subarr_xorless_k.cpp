#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

class trieNode
{
public:
    ll freq;
    trieNode *left, *right;
    trieNode()
    {
        freq = 0;
        left = NULL;
        right = NULL;
    }
};

void insert(ll n, trieNode *root)
{
    trieNode *curr = root;
    for (ll i = 31; i >= 0; i--)
    {
        ll bit = (1 << i) & n;
        if (bit)
        {
            if (!curr->right)
                curr->right = new trieNode();
            curr = curr->right;
            curr->freq++;
        }
        else
        {
            if (!curr->left)
                curr->left = new trieNode();
            curr = curr->left;
            curr->freq++;
        }
    }
}

void erase(ll n, trieNode *root)
{
    trieNode *curr = root;
    for (ll i = 31; i >= 0; i--)
    {
        ll bit = (1 << i) & n;
        if (bit)
        {
            curr->right->freq--;
            curr = curr->right;
        }
        else
        {
            curr->left->freq--;
            curr = curr->left;
        }
    }
}

ll xork(ll n, ll k, trieNode *root)
{
    trieNode *curr = root;
    ll ans = 0;
    for (ll i = 31; i >= 0; i--)
    {
        if (curr == NULL)
            break;
        ll bit = (1 << i) & n, kbit = (1 << i) & k;
        if (bit == kbit)
        {
            if (kbit)
                if (curr->right)
                    ans += curr->right->freq;
            curr = curr->left;
        }
        else
        {
            if (kbit)
                if (curr->left)
                    ans += curr->left->freq;
            curr = curr->right;
        }
    }
    return ans;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    trieNode *root = new trieNode();
    insert(0, root);
    ll ans = 0, pre = 0;
    for (int i = 0; i < n; i++)
    {
        pre ^= a[i];
        ans += xork(pre, k, root);
        insert(pre, root);
    }
    cout << ans << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}