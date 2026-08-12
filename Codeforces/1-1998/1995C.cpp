#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll last_opr = 0, ans = 0;
    for (int i = 1; i < n; i++)
    {
        ll left = a[i - 1], right = a[i];
        ll opr1 = 0, opr2 = 0;

        if (right == 1 && left > 1)
        {
            ans = -1;
            break;
        }

        while (right < left)
        {
            right *= right;
            opr2++;
        }

        while (left * left <= right)
        {
            if (left == 1)
            {
                opr1 = -1;
                break;
            }
            left *= left;
            opr1++;
        }

        if (opr2)
            last_opr += opr2;
        else if (opr1 == -1)
            last_opr = 0;
        else
            last_opr = max(0ll, last_opr - opr1);

        ans += last_opr;
    }
    cout << ans << endl;
    return;
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