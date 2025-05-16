#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll kmax = 0;
    while (kmax < n && a[kmax] > y)
        kmax++;

    vector<bool> pos(x + 1, false);
    pos[x] = true;
    vector<ll> poslist, S;
    poslist.reserve(x + 1);
    S.reserve(kmax);
    poslist.push_back(x);
    ll pri = -1;
    for (ll k = 1; k <= kmax; k++)
    {
        ll b = a[k - 1];
        S.push_back(b);
        deque<ll> q;
        for (auto u : poslist)
        {
            ll v = u % b;
            if (!pos[v])
            {
                pos[v] = true;
                q.push_back(v);
                poslist.push_back(v);
            }
        }
        while (!q.empty())
        {
            ll u = q.front();
            q.pop_front();
            for (ll d : S)
            {
                ll v2 = u % d;
                if (!pos[v2])
                {
                    pos[v2] = true;
                    q.push_back(v2);
                    poslist.push_back(v2);
                }
            }
        }
        if (pos[y] && pri < 0)
        {
            pri = k;
            break;
        }
    }
    if (pri < 0)
        cout << "0\n\n";
    else
    {
        ll L = kmax - pri + 1;
        cout << L << "\n";
        for (ll i = pri; i <= kmax; i++)
            cout << i << " ";
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}