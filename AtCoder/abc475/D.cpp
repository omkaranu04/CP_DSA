#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
string S;
ll n;
ll dig[26], vis[10];
bool isPrime(ll n)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
ll rec(ll i, ll num)
{
    if (i == n)
    {
        if (isPrime(num))
            return num;
        return -1;
    }
    ll c = S[i] - 'a';
    if (dig[c] != -1)
        return rec(i + 1, num * 10 + dig[c]);

    for (ll d = 0; d <= 9; d++)
    {
        if (i == 0 && d == 0)
            continue;
        if (vis[d])
            continue;
        dig[c] = d;
        vis[d] = 1;
        ll ans = rec(i + 1, num * 10 + d);
        if (ans != -1)
            return ans;
        dig[c] = -1;
        vis[d] = 0;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dig, -1, sizeof(dig));
    memset(vis, 0, sizeof(vis));
    cin >> S;
    n = S.length();
    cout << rec(0, 0);
    return 0;
}