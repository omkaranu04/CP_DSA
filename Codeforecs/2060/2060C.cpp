#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> freq;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        freq[x]++;
    }
    ll score = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = k - i;
        if (j >= 1 && j <= n && i < j)
        {
            score += min(freq[i], freq[j]);
        }
        else if (2 * i == k)
        {
            score += freq[i] / 2;
        }
    }
    cout << score << endl;
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