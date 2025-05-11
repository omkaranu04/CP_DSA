#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
int main()
{
    ll n, a;
    cin >> n >> a;
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s.begin(), s.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll elem = s[i];
        ll l = i + 1, r = n - 1, x = i;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (s[mid] * elem <= a)
            {
                l = mid + 1;
                x = mid;
            }
            else
                r = mid - 1;
        }
        ans += (x - i);
    }
    cout << ans << endl;
}