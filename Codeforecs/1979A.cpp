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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll mini = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            mini = min(mini, max(a[i], a[i - 1]));
        }
        cout << mini - 1 << endl;
    }
    return 0;
}