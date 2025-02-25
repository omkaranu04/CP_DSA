#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
string s;
ll n, q;
struct node
{
    ll L, O, C;
    node(ll l = 0, ll o = 0, ll c = 0)
    {
        L = l;
        O = o;
        C = c;
    }
};
vector<node> segTree;
node merge(node l, node r)
{
    node ans;
    ll temp = min(l.O, r.C);
    ans.L = l.L + r.L + 2 * temp;
    ans.O = l.O + r.O - temp;
    ans.C = l.C + r.C - temp;
    return ans;
}
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        if (s[l] == '(')
            segTree[id] = {0, 1, 0};
        else
            segTree[id] = {0, 0, 1};
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    segTree[id] = merge(segTree[2 * id], segTree[2 * id + 1]);
}
node query(ll id, ll l, ll r, ll ql, ll qr)
{
    if (ql > r || qr < l)
        return node();
    if (l >= ql && r <= qr)
        return segTree[id];
    ll mid = (l + r) / 2;
    return merge(query(2 * id, l, mid, ql, qr), query(2 * id + 1, mid + 1, r, ql, qr));
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    cin >> q;
    n = s.length();
    segTree.resize(4 * n + 1);
    build(1, 0, n - 1);
    while (q--)
    {
        ll ql, qr;
        cin >> ql >> qr;
        ql--, qr--;
        node ans = query(1, 0, n - 1, ql, qr);
        cout << ans.L << endl;
    }
    return 0;
}