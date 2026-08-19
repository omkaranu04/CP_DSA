#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m;
bool check(ll x, ll y, vector<ll> a, vector<ll> b)
{
    for (ll i = 0; i < m; i++)
    {
        if (!(a[i] == x || b[i] == x))
        {
            if (!(a[i] == y || b[i] == y))
                return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    set<pair<ll, ll>> ans;
    for (ll i = 0; i < 2; i++)
    {
        ll p;
        if (i)
            p = a[0];
        else
            p = b[0];

        ll flag = -1;
        for (ll j = 0; j < m; j++)
        {
            if (!(a[j] == p || b[j] == p))
            {
                flag = j;
                break;
            }
        }
        if (flag == -1)
        {
            for (ll j = 1; j <= n; j++)
                if (j != p)
                {
                    if (j < p)
                        ans.insert({j, p});
                    else
                        ans.insert({p, j});
                }
        }
        else
        {
            for (ll j = 0; j < 2; j++)
            {
                ll k;
                if (j)
                    k = a[flag];
                else
                    k = b[flag];

                if (check(p, k, a, b))
                {
                    if (p < k)
                        ans.insert({p, k});
                    else
                        ans.insert({k, p});
                }
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}