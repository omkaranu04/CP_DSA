#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, l, d;
        cin >> n >> d >> l;
        if (d == 1)
        {
            if (n == 2 && l == 2)
                cout << "1 2\n";
            else
                cout << "-1";
            continue;
        }
        else
        {
            ll nmin = l + d - 1;
            ll nmax = l * (d / 2) + 1 + (d % 2);
            if (n > nmax || n < nmin)
            {
                cout << -1 << endl;
                continue;
            }
            if (d % 2 == 0)
            {
                ll cnt = 2;
                ll currL = 0;
                while (true)
                {
                    ll prev = 1;
                    for (ll j = 1; j <= d / 2; j++)
                    {
                        cout << prev << " " << cnt << endl;
                        prev = cnt;
                        cnt++;
                        if (cnt == n + 1)
                            break;
                    }
                    currL++;
                    // cout << "leaves: " << currL << endl;
                    // cout << "cnt: " << cnt << endl;
                    if (cnt == n + 1)
                        break;
                    if (currL == l)
                        break;
                }
            }
            if (d % 2 == 1)
            {
                cout << "1 2\n";
                ll cnt = 3;
                ll currL = 0;
                while (true)
                {
                    ll prev = 1;
                    for (ll j = 1; j <= d / 2; j++)
                    {
                        cout << prev << " " << cnt << endl;
                        prev = cnt;
                        cnt++;
                        if (cnt == n + 1)
                            break;
                    }
                    currL++;
                    // cout << "leaves: " << currL << endl;
                    // cout << "cnt: " << cnt << endl;
                    if (cnt == n + 1)
                        break;
                    if (currL == l)
                        break;
                    prev = 2;
                    for (ll j = 1; j <= d / 2; j++)
                    {
                        cout << prev << " " << cnt << endl;
                        prev = cnt;
                        cnt++;
                        if (cnt == n + 1)
                            break;
                    }
                    currL++;
                    // cout << "leaves: " << currL << endl;
                    // cout << "cnt: " << cnt << endl;
                    if (cnt == n + 1)
                        break;
                    if (currL == l)
                        break;
                }
            }
        }
    }
    return 0;
}