#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, ans, pref[200000], suff[200000];
string s;

void solve()
{
    cin >> n >> s;

    pref[0] = ((s[0] - '>') ? -1 : 0);
    for (int i = 1; i < n; ++i)
        pref[i] = ((s[i] != '>') ? pref[i - 1] : i);

    suff[n - 1] = n;
    for (int i = n - 2; i > -1; --i)
        suff[i] = ((s[i + 1] != '<') ? suff[i + 1] : i + 1);

    ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, 2 * min(i - pref[i], suff[i] - i - 1));

    cout << ans << endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}