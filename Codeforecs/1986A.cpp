#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        vector<ll> x(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        ll ans = abs(x[0] - x[1]) + abs(x[1] - x[2]);
        cout << ans << endl;
    }
    return 0;
}