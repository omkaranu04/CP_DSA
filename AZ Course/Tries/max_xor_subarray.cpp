#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class trieNode
{
public:
    ll freq;
    trieNode *left, *right;
    trieNode()
    {
        freq = 0;
        left = NULL;  // 0
        right = NULL; // 1
    }
};

void insert(ll n, trieNode *root)
{
    trieNode *curr = root;
    for (int i = 31; i >= 0; i--)
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
    for (int i = 31; i >= 0; i--)
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

ll findXOR(ll n, trieNode *root)
{
    trieNode *curr = root;
    ll ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        ll bit = (1 << i) & n;
        if (bit)
        {
            if (curr->left && curr->left->freq > 0)
            {
                ans += (1 << i);
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
        else
        {
            if (curr->right && curr->right->freq > 0)
            {
                ans += (1 << i);
                curr = curr->right;
            }
            else
                curr = curr->left;
        }
    }
    return ans;
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
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        trieNode *root = new trieNode();
        insert(0, root);
        ll pre = 0, ans = -1;
        for(ll i=0;i<n;i++)
        {
            pre ^= a[i];
            ans = max(ans, findXOR(pre, root));
            insert(pre, root);
        }
        cout<<ans<<endl;
    }
    return 0;
}