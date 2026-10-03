#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        ll n = s.length();
        vector<ll> freq(26, 0);
        ll k = 0, m = LLONG_MIN;
        for (ll i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                k++;
                m = max(m, ++freq[s[i] - 'a']);
            }
        }
        ll ans = max(m, (k + 1) / 2);
        cout << ans + 1 << endl;
    }
    return 0;
}