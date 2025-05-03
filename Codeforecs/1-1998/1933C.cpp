#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, l;
        cin >> a >> b >> l;
        set<ll> ans;
        for (ll i = 0; i < 50; i++)
        {
            for (ll j = 0; j < 50; j++)
            {
                ll exp = pow(a, i) * pow(b, j);
                if (l % exp == 0)
                {
                    ans.insert(l / exp);
                }
            }
        }
        cout << ans.size() << endl;
    }
    return 0;
}