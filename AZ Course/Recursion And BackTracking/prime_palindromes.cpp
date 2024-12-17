#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll ans = 0;
bool isPrime(ll n)
{
    if (n == 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void solve(ll curr, ll total_len, ll currlen, ll a, ll b)
{
    // reached halfway of generation so create a palindrome
    if (currlen == (total_len + 1) / 2)
    {
        vector<ll> v;
        ll temp = curr;
        while (temp)
        {
            v.push_back(temp % 10);
            temp /= 10;
        }
        temp = curr;
        for (ll i = (total_len % 2); i < v.size(); i++)
        {
            temp = temp * 10 + v[i];
        }
        if (temp >= a && temp <= b && isPrime(temp))
        {
            ans++;
        }
        return;
    }

    for (ll i = 0; i <= 9; i++)
    {
        curr = curr * 10 + i;
        solve(curr, total_len, currlen + 1, a, b);
        curr /= 10;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    ll temp = b;
    ll len = 0;
    while (temp)
    {
        len++;
        temp /= 10;
    }
    for (ll i = 1; i <= len; i++)
    {
        for (ll j = 1; j <= 9; j++)
        {
            solve(j, i, 1LL, a, b);
        }
    }
    cout << ans << "\n";
    return 0;
}