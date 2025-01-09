#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        vector<ll> a; // a is array rep. of the string
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
                a.push_back(-1);
            else
                a.push_back(1);
        }
        vector<ll> ps(a.size() + 1); // prefix sum of -1 if 0 and +1 if 1
        ps[0] = 0;
        for (int i = 1; i <= a.size(); i++)
        {
            ps[i] = ps[i - 1] + a[i - 1];
        }
        ll ans = 0;
        unordered_map<ll, ll> hash;
        for (int i = 0; i <= a.size(); i++)
        {
            ans = (ans + (n - i + 1) * hash[ps[i]]) % mod;
            hash[ps[i]] = (hash[ps[i]] + (i + 1)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}