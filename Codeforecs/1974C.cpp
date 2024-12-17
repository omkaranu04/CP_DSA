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
        map<tuple<ll, ll, ll>, ll> count;
        ll ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            tuple<ll, ll, ll> triplet = make_tuple(a[i], a[i + 1], a[i + 2]);
            tuple<int, int, int> mist[3] = {
                make_tuple(0, a[i + 1], a[i + 2]),
                make_tuple(a[i], 0, a[i + 2]),
                make_tuple(a[i], a[i + 1], 0)};

            for (int j = 0; j < 3; j++)
            {
                ans += count[mist[j]] - count[triplet];
                count[mist[j]]++;
            }
            count[triplet]++;
        }
        cout << ans << endl;
    }
    return 0;
}