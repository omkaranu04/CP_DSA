#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void sieveOfEratosthenes(ll n)
{
    vector<bool> prime(n + 1, true);
    vector<ll> answer;

    prime[0] = prime[1] = false;

    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (ll p = 2; p <= n; p++)
    {
        if (prime[p])
            answer.push_back(p);
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll k;
        cin >> k;
        cout << answer[k - 1] << endl;
    }
}
int main(int argc, char const *argv[])
{
    ll n = 100000000;
    sieveOfEratosthenes(n);
    return 0;
}