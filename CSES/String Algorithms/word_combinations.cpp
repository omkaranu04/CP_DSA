#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll B = 999999937;
struct stringHash
{
    string s;
    ll n;
    vector<ll> p, hash;
    stringHash(const string &a, const ll base = B) : s(a)
    {
        n = s.length();
        p.resize(n + 1);
        hash.resize(n + 1);
        p[0] = 1;
        hash[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            p[i] = (p[i - 1] * 1LL * base) % mod;
            hash[i] = ((hash[i - 1] * 1LL * base) % mod + (s[i - 1] - 'a' + 1) % mod) % mod;
        }
    }
    // return hash of s[l ... l + len - 1], -1 if invalid;
    ll getHash(ll l, ll len)
    {
        ll r = l + len;
        if (l < 0 || r > n)
            return -1;
        ll retval = (hash[r] - (hash[l] * 1LL * p[len]) % mod + mod) % mod;
        return retval;
    }
};
ll HASH(const string &s, const ll base = B)
{
    ll n = s.length();
    ll retval = 0;
    for (ll i = 0; i < n; i++)
        retval = ((retval * 1LL * base) % mod + (s[i] - 'a' + 1) % mod) % mod;
    return retval;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll n = s.length();
    ll k;
    cin >> k;

    vector<vector<ll>> dictHash(n + 1);
    for (ll i = 0; i < k; i++)
    {
        string tmp;
        cin >> tmp;
        dictHash[tmp.length()].push_back(HASH(tmp));
    }

    vector<ll> lengths;
    for (ll len = 1; len <= n; len++)
    {
        auto &v = dictHash[len];
        if (v.empty())
            continue;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        lengths.push_back(len);
    }

    stringHash sh(s);
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        if (dp[i] == 0)
            continue;
        for (auto len : lengths)
        {
            ll j = i + len;
            if (j > n)
                break;
            ll substrhash = sh.getHash(i, len);
            auto &v = dictHash[len];
            if (binary_search(v.begin(), v.end(), substrhash))
                dp[j] = (dp[j] + dp[i]) % mod;
        }
    }

    cout << dp[n] << endl;
    return 0;
}