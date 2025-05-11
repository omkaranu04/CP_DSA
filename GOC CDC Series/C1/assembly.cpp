#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        multiset<ll> odd, even;
        vector<bool> evenpos(n, false);
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x % 2 == 0)
            {
                evenpos[i] = true;
                even.insert(x);
            }
            else
                odd.insert(x);
        }
        for (int i = 0; i < n; i++)
        {
            if (evenpos[i])
            {
                auto it = even.begin();
                cout << *it << " ";
                even.erase(it);
            }
            else
            {
                auto it = odd.begin();
                cout << *it << " ";
                odd.erase(it);
            }
        }
        cout << endl;
    }
}