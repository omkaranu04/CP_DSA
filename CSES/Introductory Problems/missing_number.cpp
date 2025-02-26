#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ll x;
        cin >> x;
        sum += x;
    }
    cout << (n * (n + 1) / 2) - sum << endl;
    return 0;
}