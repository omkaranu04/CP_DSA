#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> v;
    ll q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        else if (t == 2)
        {
            ll k;
            cin >> k;
            cout << v[v.size() - k] << endl;
        }
    }
    return 0;
}