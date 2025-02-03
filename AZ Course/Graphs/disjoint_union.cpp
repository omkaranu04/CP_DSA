#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, q, set_size;
vector<ll> parent, rank_s;
ll find(ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void merge(ll x, ll y)
{
    ll xroot = find(x), yroot = find(y);
    if (xroot == yroot)
        return;
    if (rank_s[xroot] <= rank_s[yroot])
    {
        parent[xroot] = yroot;
        rank_s[yroot] += rank_s[xroot];
    }
    else
    {
        parent[yroot] = xroot;
        rank_s[xroot] += rank_s[yroot];
    }
    set_size--;
}
void reset()
{
    for (ll i = 0; i < n; i++)
    {
        parent[i] = i;
        rank_s[i] = 1;
    }
    set_size = n;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    parent.resize(n);
    rank_s.resize(n, 1);
    set_size = n;
    for (ll i = 0; i < n; i++)
        parent[i] = i;
    while (q--)
    {
        ll type, x, y;
        cin >> type >> x >> y;
        if (type == 0)
        {
            merge(x, y);
        }
        else
        {
            // cout << "ans : ";
            if (find(x) == find(y))
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    return 0;
}