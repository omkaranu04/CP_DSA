#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPossible(vector<ll> &a, ll mid, ll c)
{
    ll cows = 1, last = a[0];
    for (ll i = 1; i < a.size(); i++)
    {
        if (a[i] - last >= mid)
        {
            cows++;
            last = a[i];
        }
    }
    if (cows >= c)
        return true;
    else
        return false;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll low = 1, high = a[n - 1] - a[0];
        while (low <= high)
        {
            ll mid = (low + high) / 2;
            if (isPossible(a, mid, c))
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << high << endl;
    }
    return 0;
}