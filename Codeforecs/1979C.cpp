#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> k(n);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    ll randn = 1;
    for (int i = 0; i < n; i++)
    {
        randn = lcm(randn, k[i]);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (randn / k[i]);
    }
    if (sum < randn)
    {
        for (int i = 0; i < n; i++)
        {
            cout << randn / k[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return;
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