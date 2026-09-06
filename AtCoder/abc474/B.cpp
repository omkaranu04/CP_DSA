#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> p(n);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    bool flag = true;
    for (ll i = 0; i < n; i++)
    {
        ll g = i / 10;
        ll l = g * 10 + 1, r = min((g + 1) * 10, n);
        if (p[i] < l || p[i] > r)
        {
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes\n" : "No\n");
    return 0;
}
