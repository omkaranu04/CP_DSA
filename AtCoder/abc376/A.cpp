#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, c;
    cin >> n >> c;
    vector<ll> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    ll ans = 1;
    ll last = t[0];
    for (int i = 1; i < n; i++)
    {
        if (t[i] - last >= c)
        {
            last = t[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}