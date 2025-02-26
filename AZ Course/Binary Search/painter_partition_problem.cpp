#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(const vector<ll> &x, ll mid, int k)
{
    int required = 1;
    ll curr_capacity = mid;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] > mid)
            return false;
        if (curr_capacity - x[i] >= 0)
        {
            curr_capacity -= x[i];
        }
        else
        {
            required++;
            curr_capacity = mid - x[i];
        }
    }
    return required <= k;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        sum += x[i];
    }

    ll low = *max_element(x.begin(), x.end());
    ll high = sum;
    ll ans = high;

    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (check(x, mid, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
