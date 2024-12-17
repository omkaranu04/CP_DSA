#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (ll i = 0; i < n; i++)
    {
        ll target = x - a[i].first;
        ll left = i + 1, right = n - 1;

        while (left < right)
        {
            ll sum = a[left].first + a[right].first;
            if (sum == target)
            {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << "\n";
                return 0;
            }
            if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
