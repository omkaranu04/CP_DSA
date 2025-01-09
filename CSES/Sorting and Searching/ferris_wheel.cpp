#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    ll ans = 0;
    for (ll i = 0, j = n - 1; i <= j;)
    {
        if (p[i] + p[j] <= x)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}