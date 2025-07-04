#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
struct Node
{
    ll val;
    Node *left, *right;
    Node(ll x) : val(x), left(NULL), right(NULL) {}
};
struct BT
{
    ll n, st;
    vector<ll> a;
    Node *root;

    BT(ll _n, vector<ll> &_a) : n(_n), a(_a), st(0LL)
    {
        root = build(st);
    }

    Node *build(ll &idx)
    {
        if (a[idx] == -1)
            return NULL;
        Node *tmp = new Node(a[idx]);
        idx++;
        tmp->left = build(idx);
        idx++;
        tmp->right = build(idx);
        return tmp;
    }

    void preorder(Node *root, vector<ll> &a)
    {
        if (root == NULL)
            return;
        a.push_back(root->val);
        preorder(root->left, a);
        preorder(root->right, a);
    }

    void inorder(Node *root, vector<ll> &a)
    {
        if (root == NULL)
            return;
        inorder(root->left, a);
        a.push_back(root->val);
        inorder(root->right, a);
    }

    void postorder(Node *root, vector<ll> &a)
    {
        if (root == NULL)
            return;
        postorder(root->left, a);
        postorder(root->right, a);
        a.push_back(root->val);
    }
    ll morris1(Node *root)
    {
        ll cnt = 0;
        Node *curr = root;
        while (curr)
        {
            if (curr->left == NULL)
            {
                cnt++;
                curr = curr->right;
            }
            else
            {
                Node *pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;
                if (pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    cnt++;
                    curr = curr->right;
                }
            }
        }
        return cnt;
    }
    ll morris2(Node *root, ll k1, ll k2)
    {
        ll cnt = 0;
        ll v1 = -1, v2 = -1;
        Node *curr = root;
        while (curr)
        {
            if (curr->left == NULL)
            {
                cnt++;
                if (cnt == k1)
                    v1 = curr->val;
                if (cnt == k2)
                    v2 = curr->val;
                curr = curr->right;
            }
            else
            {
                Node *pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;
                if (pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    cnt++;
                    if (cnt == k1)
                        v1 = curr->val;
                    if (cnt == k2)
                        v2 = curr->val;
                    curr = curr->right;
                }
            }
        }
        if (v1 == -1 || v2 == -1)
            return 0;

        return (v1 + v2) / 2;
    }
};
void solve()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (ll i = 0; i < N; i++)
        cin >> a[i];

    BT tree(N, a);
    ll n = tree.morris1(tree.root);
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    ll k1 = (n % 2 == 0) ? (n / 2) : ((n + 1) / 2);
    ll k2 = (n % 2 == 0) ? (n / 2 + 1) : k1;

    cout << tree.morris2(tree.root, k1, k2) << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}