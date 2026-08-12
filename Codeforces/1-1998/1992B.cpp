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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll steps = 0;
        for (int i = 0; i < k - 1; i++)
        {
            steps += (a[i] - 1) + a[i];
        }
        cout << steps << endl;
    }
    return 0;
}