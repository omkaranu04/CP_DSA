#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n), c(n);
    for (int i = 1; i < n; i++)
        cin >> c[i];
    for (int i = 1; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    while (1)
    {
        ll last = 0;
        for (int i = 1; i < n; i++)
            if (a[i])
                last = i;
        if (last == 0)
            break;

        ans++;
        int fr = -1, curr = n;
        for (int i = last - c[last]; i < last; i++)
        {
            if (i - c[i] < curr)
            {
                curr = i - c[i];
                fr = i;
            }
            if (a[i])
            {
                a[last] = 0;
                break;
            }
        }

        if (a[last])
        {
            a[fr] = 1;
            a[last] = 0;
        }
    }

    cout << ans << endl;
    return 0;
}