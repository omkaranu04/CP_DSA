#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;
    multiset<ll> tickets; // for auto sorting
    vector<ll> customers(m);

    for (ll i = 0; i < n; i++)
    {
        ll price;
        cin >> price;
        tickets.insert(price);
    }

    for (ll i = 0; i < m; i++)
    {
        cin >> customers[i];
    }

    for (ll i = 0; i < m; i++)
    {
        auto it = tickets.upper_bound(customers[i]);
        if (it == tickets.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            it--;
            cout << *it << endl;
            tickets.erase(it);
        }
    }

    return 0;
}
