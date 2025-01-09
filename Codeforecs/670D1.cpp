#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool can_bake(vector<ll> &a, vector<ll> &b, ll k, ll x, ll n)
{
    ll required_k = 0;
    for (int i = 0; i < n; i++)
    {
        ll needed = a[i] * x;
        if (needed > b[i])
        {
            required_k += needed - b[i];
        }
        if (required_k > k)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll left = 0;
    ll right = 10000000000;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (can_bake(a, b, k, mid, n))
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << right << endl;
    return 0;
}