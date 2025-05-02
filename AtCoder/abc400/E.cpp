#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MAX 1000100 
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> primes(MAX);
    for (int i = 2; i < MAX; i++)
    {
        if (primes[i] == 0)
        {
            for (int j = i; j < MAX; j += i)
                primes[j]++;
        }
    }
    set<ll> s;
    for (ll i = 2; i < MAX; i++)
    {
        if (primes[i] == 2)
            s.insert(1LL * i * i);
    }
    ll q;
    cin >> q;
    vector<ll> ans;
    while (q--)
    {
        ll a;
        cin >> a;
        cout << (*(--(s.upper_bound(a)))) << endl;
    }
    return 0;
}