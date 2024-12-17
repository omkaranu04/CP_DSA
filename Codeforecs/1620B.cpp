#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll w, h;
        cin >> w >> h;
        ll k;
        vector<ll> hori1, hori2, ver1, ver2;

        cin >> k;
        hori1.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> hori1[i];
        }

        cin >> k;
        hori2.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> hori2[i];
        }

        cin >> k;
        ver1.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> ver1[i];
        }

        cin >> k;
        ver2.resize(k);
        for (int i = 0; i < k; i++)
        {
            cin >> ver2[i];
        }

        sort(hori1.begin(), hori1.end());
        sort(hori2.begin(), hori2.end());
        sort(ver1.begin(), ver1.end());
        sort(ver2.begin(), ver2.end());

        ll a1 = (hori1[hori1.size() - 1] - hori1[0]) * h;
        ll a2 = (hori2[hori2.size() - 1] - hori2[0]) * h;
        ll a3 = (ver1[ver1.size() - 1] - ver1[0]) * w;
        ll a4 = (ver2[ver2.size() - 1] - ver2[0]) * w;

        ll ans = max({a1, a2, a3, a4});
        cout << ans << endl;
    }
    return 0;
}