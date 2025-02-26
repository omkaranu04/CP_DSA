#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll const N = 1e6 + 10;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> x(n), cnt(N + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i];
        cnt[x[i]]++;
    }
    for (ll i = N; i >= 1; i--)
    {
        ll temp = 0;
        for (ll j = i; j <= N; j += i)
        {
            temp += cnt[j];
        }
        if (temp >= 2)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}