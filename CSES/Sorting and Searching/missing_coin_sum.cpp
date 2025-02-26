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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll sum = 1LL;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > sum)
        {
            cout << sum << endl;
            return 0;
        }
        else
        {
            sum += a[i];
        }
    }
    cout << sum << endl;
    return 0;
}