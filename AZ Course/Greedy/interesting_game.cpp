#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first + a.second > b.first + b.second;
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ab(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> ab[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> ab[i].second;
    }
    sort(ab.begin(), ab.end(), cmp);
    ll p1 = 0, p2 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            p1 += ab[i].first;
        }
        else
        {
            p2 += ab[i].second;
        }
    }
    if (p1 > p2)
        cout << "Alice\n";
    else if (p1 < p2)
        cout << "Bob\n";
    else
        cout << "Tie\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}