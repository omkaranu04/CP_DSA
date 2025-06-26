#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 5;
vector<bool> isprime(MAXN, true);
vector<ll> cntprime(MAXN, 0);
void sieve(ll n)
{
    isprime[0] = false;
    isprime[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            for (ll j = 2 * i; j <= n; j += i)
                isprime[j] = false;
        }
        cntprime[i] = cntprime[i - 1] + (ll)isprime[i];
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, X, R1, R2;
    cin >> N >> X >> R1 >> R2;

    sieve(N + 10);

    vector<bool> special(N + 1, false);
    for (ll i = 1; i <= N; i++)
    {
        if (cntprime[i] * R2 >= R1 * i)
            special[i] = true;
    }

    vector<ll> dist(N + 1, -1);
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        ll curr = q.front();
        q.pop();

        if (curr + 1 <= N && dist[curr + 1] == -1)
        {
            dist[curr + 1] = dist[curr] + 1;
            q.push(curr + 1);
        }
        if (special[curr] && curr + X <= N && dist[curr + X] == -1)
        {
            dist[curr + X] = dist[curr] + 1;
            q.push(curr + X);
        }
    }

    cout << dist[N];
    return 0;
}