#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> ratings(n), a, b(m); // n players, m problems
    for (ll i = 0; i < n; i++)
    {
        cin >> ratings[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    // high rated only matter
    a.push_back(ratings[0]);
    for (ll i = 1; i < n; i++)
    {
        if (ratings[i] > a[0])
        {
            a.push_back(ratings[i]);
        }
    }
    ll asize = a.size();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> tmp;
    // 1 problem, how many?
    for (ll i = 0, j = 0; i < m; i++)
    {
        while (j < asize && a[j] < b[i])
            j++;
        if (j > 0 && j < asize)
            tmp.push_back(asize - j);
    }
    // if all not matter, if none not matter
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());

    for (ll i = 1; i <= m; i++)
    {
        ll rem = m % i;
        ll contests = m / i;

        for (ll j = rem; j < tmp.size(); j += i)
        {
            contests += tmp[j];
        }
        cout << contests << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}