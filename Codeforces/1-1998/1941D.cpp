#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, x;
        cin >> n >> m >> x;
        x--;

        set<ll> q;
        q.insert(x);

        for (ll i = 0; i < m; i++)
        {
            ll r;
            char c;
            cin >> r >> c;

            set<ll> next;
            for (auto u : q)
            {
                if (c == '0')
                {
                    ll v = (u + r) % n;
                    next.insert(v);
                }
                else if (c == '1')
                {
                    ll v = (u - r + n) % n;
                    next.insert(v);
                }
                else
                {
                    ll v1 = (u + r) % n;
                    ll v2 = (u - r + n) % n;
                    next.insert(v1);
                    next.insert(v2);
                }
            }
            q = next;
        }

        cout << q.size() << endl;
        for (auto x : q)
            cout << x + 1 << " ";
        cout << endl;
    }

    return 0;
}