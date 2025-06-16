#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
struct Node
{
    ll val, sz;
    Node *left, *right;
    Node(ll x) : val(x), sz(1), left(NULL), right(NULL) {}
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

        ll lsz = tmp->left ? tmp->left->sz : 0;
        ll rsz = tmp->right ? tmp->right->sz : 0;
        tmp->sz = 1 + lsz + rsz;

        return tmp;
    }

    ll getKthElem(Node *root, ll k)
    {
        if (root == NULL || k <= 0 || k > root->sz)
            return -1;
        ll lsz = root->left ? root->left->sz : 0;
        if (k == lsz + 1)
            return root->val;
        if (k <= lsz)
            return getKthElem(root->left, k);
        else
            return getKthElem(root->right, k - lsz - 1);
    }
};
void solve()
{
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (ll i = 0; i < N; i++)
        cin >> a[i];
    BT tree(N, a);

    while (Q--)
    {
        ll k;
        cin >> k;
        cout << tree.getKthElem(tree.root, k) << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}