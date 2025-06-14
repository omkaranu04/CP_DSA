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

    void level_order(Node *root, vector<vector<ll>> &a)
    {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            ll sz = q.size();
            vector<ll> level;

            for (ll i = 0; i < sz; i++)
            {
                Node *curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }

            a.push_back(level);
        }
    }

    void zigzaglevelorder(Node *root, vector<vector<ll>> &a)
    {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);
        bool torev = false;
        while (!q.empty())
        {
            ll sz = q.size();
            vector<ll> level;

            for (ll i = 0; i < sz; i++)
            {
                Node *curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }

            if (torev)
                reverse(level.begin(), level.end());
            torev = !torev;
            a.push_back(level);
        }
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
    vector<vector<ll>> ans;
    tree.zigzaglevelorder(tree.root, ans);
    for (auto x : ans)
    {
        for (auto xx : x)
            cout << xx << " ";
        cout << endl;
    }
    cout << endl;
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