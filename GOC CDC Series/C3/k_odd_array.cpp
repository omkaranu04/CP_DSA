#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll atmostkodds(vector<ll> &a, ll k, ll n)
{
    ll j = -1, i = 0, cnt = 0, ans = 0;
    while (i < n)
    {
        while (j + 1 < n && (cnt + (a[j + 1] % 2 == 1)) <= k)
        {
            j++;
            if (a[j] % 2 == 1)
                cnt++;
        }
        if (cnt <= k)
            ans += (j - i + 1);
        if (i > j)
        {
            i++;
            j = i - 1;
        }
        else
        {
            if (a[i] % 2 == 1)
                cnt--;
            i++;
        }
    }
    return ans;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = atmostkodds(a, k, n) - atmostkodds(a, k - 1, n);
    cout << ans << endl;
    return 0;
}
