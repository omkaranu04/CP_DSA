#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    string s, t;
    cin >> q >> s >> t;
    ll n = s.length(), m = t.length();
    vector<ll> match(n, 0);
    for (ll i = 0; i + m <= n; i++)
    {
        if (s.substr(i, m) == t)
            match[i] = 1;
    }
    vector<ll> ps(n + 1, 0);
    for (ll i = 0; i < n; i++)
        ps[i + 1] = ps[i] + match[i];
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll lmin = r - m + 1;
        if (lmin < l)
        {
            cout << "No\n";
            continue;
        }
        ll ans = ps[lmin + 1] - ps[l];
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}