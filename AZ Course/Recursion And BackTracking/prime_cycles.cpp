#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> primes(10001, 1);
int ans = 0;
void solve(vector<bool> &visited, ll curr, ll n, int count)
{
    if (count == n)
    {
        if (primes[1 + curr])
            ans++;
        return;
    }
    for (ll i = 2; i <= n; i++)
    {
        if (!visited[i] && primes[i + curr] && (i % 2 != curr % 2))
        {
            visited[i] = true;
            count++;
            solve(visited, i, n, count);
            count--;
            visited[i] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << "0\n";
        return 0;
    }
    primes[0] = primes[1] = 0;
    for (ll i = 2; i * i <= 1000; i++)
    {
        if (primes[i])
        {
            for (ll j = i * i; j <= 1000; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    solve(visited, 1, n, 1);
    cout << ans << "\n";
    return 0;
}