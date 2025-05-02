#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    ll ans = 0, add = 1;

    for (ll i = 0; i <= m; ++i)
    {
        if (ans > 1e9)
        {
            cout << "inf\n";
            return 0;
        }
        ans += add;
        if (ans > 1e9)
        {
            cout << "inf\n";
            return 0;
        }
        if (i != m)
        {
            if (add > 1e9 / n)
            {
                cout << "inf\n";
                return 0;
            }
            add *= n;
        }
    }

    if (ans > 1e9)
        cout << "inf\n";
    else
        cout << ans << endl;

    return 0;
}
