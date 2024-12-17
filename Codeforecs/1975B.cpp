#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    bool possible = false;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            possible = true;
    }
    if (possible)
        return true;
    else
    {
        sort(a.begin(), a.end());
        ll something = a[0];
        vector<ll> b;
        for (ll i = 1; i < n; i++)
        {
            if (a[i] % something != 0)
                b.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        ll something2 = b[0];
        for (ll j = 1; j < b.size(); j++)
        {
            if (b[j] % something2 != 0)
                possible = true;
        }
        if (!possible)
            return true;
        else
            return false;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}