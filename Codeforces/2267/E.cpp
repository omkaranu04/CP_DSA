#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll con(string &s, ll i)
{
    ll n = s.length() - 1;
    if (i < 1 || i >= n)
        return 0;
    if (s[i] != s[i + 1])
        return i * (n - i);
    return 0;
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
        ll n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        s = " " + s;
        vector<ll> freq(2, 0);
        for (ll i = 1; i <= n; i++)
            freq[s[i] - '0']++;

        ll ans = 0;
        for (ll i = 1; i < n; i++)
            ans += con(s, i);
        cout << ((ans + freq[0] * freq[1]) / 2) << " ";
        while (q--)
        {
            ll i;
            cin >> i;
            ans -= (con(s, i - 1) + con(s, i));

            freq[s[i] - '0']--;
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
            freq[s[i] - '0']++;

            ans += (con(s, i - 1) + con(s, i));
            cout << ((ans + freq[0] * freq[1]) / 2) << " ";
        }
        cout << endl;
    }
    return 0;
}