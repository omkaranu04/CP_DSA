#include <bits/stdc++.h>
using namespace std;
#define ll int
int check(vector<ll> &a, int mid, int n)
{
    if (mid == n - 1)
        return 1;
    if (a[mid] > a[mid + 1])
        return 1;
    return 0;
}

void bin_search1(vector<ll> &a, ll low, ll high, ll k)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == k)
        {
            cout << mid + 1 << " ";
            return;
        }
        else if (a[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

void bin_search2(vector<ll> &a, ll low, ll high, ll k)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == k)
        {
            cout << mid + 1 << " ";
            return;
        }
        else if (a[mid] > k)
            low = mid + 1;
        else
            high = mid - 1;
    }
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll low = 0, high = n - 1, peak = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(a, mid, n) == 1)
        {
            peak = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    while (q--)
    {
        ll k;
        cin >> k;
        bin_search1(a, 0, peak - 1, k);
        bin_search2(a, peak, n - 1, k);
        cout << endl;
    }
}

int main(int argc, char const *argv[])
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