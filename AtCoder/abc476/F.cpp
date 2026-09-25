#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll abssum(vector<ll> &ps1, vector<ll> &ps2, ll t)
{
    ll n = ps1.size() - 1;
    ll l1 = ps1[t + 1], l2 = ps2[t + 1];
    ll t1 = ps1[n], t2 = ps2[n];
    ll r1 = t1 - l1, r2 = t2 - l2;
    ll left = t * l1 - l2;
    ll right = r2 - t * r1;
    return left + right;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<ll> sumS(2 * n - 1, 0), sumD(2 * n - 1, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll w = (a[i] * b[j]) % m;
            sumS[i + j] += w;
            sumD[i - j + n - 1] += w;
        }
    }
    vector<ll> ps11(2 * n, 0), ps12(2 * n, 0);
    vector<ll> ps21(2 * n, 0), ps22(2 * n, 0);
    for (ll i = 0; i < 2 * n - 1; i++)
    {
        ps11[i + 1] = ps11[i] + sumS[i];
        ps12[i + 1] = ps12[i] + sumS[i] * i;
        ps21[i + 1] = ps21[i] + sumD[i];
        ps22[i + 1] = ps22[i] + sumD[i] * i;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll s0 = i + j, d0 = i - j + n - 1;
            ll s = abssum(ps11, ps12, s0);
            ll d = abssum(ps21, ps22, d0);
            ans ^= ((s + d) / 2 + i * n + j);
        }
    }
    cout << ans << endl;
    return 0;
}