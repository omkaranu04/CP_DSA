#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    string s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;
    vector<ll> ps(n + 1);
    ps[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + a[i - 1];
    }
    ll l = 0, r = n - 1;
    ll ans = 0;
    while (l < r)
    {
        if (s[l] == 'L' && s[r] == 'R')
        {
            ans += ps[r + 1] - ps[l];
            l++;
            r--;
        }
        else if (s[l] == 'L' && s[r] == 'L')
            r--;
        else if (s[l] == 'R' && s[r] == 'R')
            l++;
        else
        {
            l++;
            r--;
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
