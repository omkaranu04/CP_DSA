#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 998244353;
vector<ll> pow2(100100);
void solve()
{
    ll n;
    cin >> n;
    vector<ll> p(n), q(n), r(n);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    for (ll i = 0; i < n; i++)
        cin >> q[i];
    vector<ll> pmax(n), ppos(n), qmax(n), qpos(n);
    pmax[0] = p[0], ppos[0] = 0;
    qmax[0] = q[0], qpos[0] = 0;
    for (ll i = 1; i < n; i++)
    {
        if (p[i] > pmax[i - 1])
        {
            pmax[i] = p[i];
            ppos[i] = i;
        }
        else
        {
            pmax[i] = pmax[i - 1];
            ppos[i] = ppos[i - 1];
        }

        if (q[i] > qmax[i - 1])
        {
            qmax[i] = q[i];
            qpos[i] = i;
        }
        else
        {
            qmax[i] = qmax[i - 1];
            qpos[i] = qpos[i - 1];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        ll pi = pmax[i], qi = qmax[i];
        ll posp = ppos[i], posq = qpos[i];

        ll ifpmax = q[i - posp];
        ll ifqmax = p[i - posq];

        ll sump = (pow2[pi] + pow2[ifpmax]) % mod;
        ll sumq = (pow2[qi] + pow2[ifqmax]) % mod;

        if (pi > qi)
            r[i] = sump;
        else if (pi < qi)
            r[i] = sumq;
        else
        {
            if (ifpmax > ifqmax)
                r[i] = sump;
            else
                r[i] = sumq;
        }
    }
    for (ll i = 0; i < n; i++)
        cout << r[i] << " ";
    cout << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pow2[0] = 1;
    pow2[1] = 2;
    for (ll i = 2; i < 100100; i++)
        pow2[i] = (pow2[i - 1] % mod + pow2[i - 1] % mod) % mod;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}