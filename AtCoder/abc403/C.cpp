#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, q;
    cin >> n >> m >> q;

    unordered_set<ll> global_access_users;
    vector<unordered_set<ll>> page_access(m + 1);

    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            page_access[y].insert(x);
        }
        else if (t == 2)
        {
            ll x;
            cin >> x;
            global_access_users.insert(x);
        }
        else
        {
            ll x, y;
            cin >> x >> y;
            if (global_access_users.count(x) || page_access[y].count(x))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}
