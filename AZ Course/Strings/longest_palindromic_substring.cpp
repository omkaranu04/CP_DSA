#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    string t = "#";
    for (auto c : s)
    {
        t.push_back(c);
        t.push_back('#');
    }
    ll m = t.length();
    vector<ll> p(m, 1);
    p[0] = 1;
    ll l = 1, r = 1;
    for (ll i = 1; i < m; i++)
    {
        p[i] = max(0LL, min(r - i, p[l + r - i]));
        while (i - p[i] >= 0 && i + p[i] < m && t[i - p[i]] == t[i + p[i]])
            p[i]++;
        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
    ll len = 0, centre = 0;
    for (ll i = 0; i < m; i++)
    {
        if (p[i] - 1 > len)
        {
            len = p[i] - 1;
            centre = i;
        }
    }
    ll start = (centre - len) / 2;
    cout << s.substr(start, len) << endl;
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
    return 0;
}