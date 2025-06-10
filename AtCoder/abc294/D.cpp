#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    set<ll> temp1, temp2;
    for (ll i = 1; i <= n; i++)
        temp1.insert(i);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x = *temp1.begin();
            temp1.erase(temp1.begin());
            temp2.insert(x);
        }
        else if (t == 2)
        {
            ll x;
            cin >> x;
            temp2.erase(x);
        }
        else
            cout << *temp2.begin() << endl;
    }
    return 0;
}