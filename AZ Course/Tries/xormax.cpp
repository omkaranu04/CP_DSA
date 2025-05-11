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
    ll q;
    cin >> q;
    trieNode *root = new trieNode();
    insert(0, root);
    while (q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
            insert(x, root);
        else if (c == '-')
            erase(x, root);
        else
            cout << findXOR(x, root) << endl;
    }
    return 0;
}