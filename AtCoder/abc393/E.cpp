#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll max_elem = *max_element(a.begin(), a.end());
    vector<ll> freq(max_elem + 1, 0), multiples(max_elem + 1, 0);
    for (ll i = 0; i < n; i++)
        freq[a[i]]++;
    for (ll i = 1; i <= max_elem; i++)
    {
        for (ll j = i; j <= max_elem; j += i)
        {
            multiples[j] += freq[i];
        }
    }
    return 0;
}