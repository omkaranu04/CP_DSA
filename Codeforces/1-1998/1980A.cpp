#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<ll> freq(7, 0);
        for (ll i = 0; i < n; i++)
        {
            freq[s[i] - 'A']++;
        }
        ll ans = 0;
        for (ll i = 0; i < 7; i++)
        {
            if (freq[i] < m)
                ans += abs(freq[i] - m);
        }
        cout << ans << endl;
    }
    return 0;
}