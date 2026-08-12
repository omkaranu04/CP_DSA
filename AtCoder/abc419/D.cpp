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
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<ll> ps(n + 2, 0);
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        ps[l] += 1;
        ps[r + 1] -= 1;
    }
    for (ll i = 1; i < n + 2; i++)
        ps[i] += ps[i - 1];
    for (ll i = 1; i <= n; i++)
    {
        if (ps[i] % 2 == 1)
            swap(s[i - 1], t[i - 1]);
    }
    cout << s << endl;
    return 0;
}