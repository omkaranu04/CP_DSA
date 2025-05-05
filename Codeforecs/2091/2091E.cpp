#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MAXN 10000001
vector<bool> prime(MAXN, true);
vector<ll> p;
void sieve()
{
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i < MAXN; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = false;
        }
    }
    for (int i = 2; i < MAXN; i++)
    {
        if (prime[i])
            p.push_back(i);
    }
}
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (auto y : p)
    {
        if (y > n)
            break;
        ans += (n / y);
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    sieve();
    while (t--)
    {
        solve();
    }
    return 0;
}