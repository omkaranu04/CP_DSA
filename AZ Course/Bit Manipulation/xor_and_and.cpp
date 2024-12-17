#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const ll N = 100001;
const ll BITS = 31;
vector<ll> powers_of_2;
ll addMod(ll a, ll b)
{
    a = a + b;
    if (a >= mod)
        a -= mod;
    return a;
}
ll nc2(ll x)
{
    return ((x * (x - 1)) / 2) % mod;
}
ll sum_of_xor_of_all(vector<ll> &a)
{
    ll ans = 0;
    for (ll i = 0; i < BITS; i++)
    {
        ll cnt1 = 0, cnt0 = 0;
        for (ll j = 0; j < a.size(); j++)
        {
            if (a[j] & (1LL << i))
            {
                cnt1++;
            }
            else
            {
                cnt0++;
            }
        }
        ans = addMod(ans, (1LL << i) * cnt0 % mod * cnt1 % mod);
    }
    return ans;
}

ll sum_of_subset_xors(vector<ll> &a)
{
    ll ans = 0;
    for (ll i = 0; i < BITS; i++)
    {
        ll cnt1 = 0;
        for (ll j = 0; j < a.size(); j++)
        {
            if (a[j] & (1LL << i))
            {
                cnt1++;
            }
        }
        if (cnt1)
            ans = addMod(ans, (1LL << i) * powers_of_2[a.size() - 1] % mod);
    }
    return ans;
}

ll sum_of_and_of_all(vector<ll> &a)
{
    ll ans = 0;
    for (ll i = 0; i < BITS; i++)
    {
        ll cnt1 = 0;
        for (ll j = 0; j < a.size(); j++)
        {
            if (a[j] & (1LL << i))
            {
                cnt1++;
            }
        }
        ans = addMod(ans, (1LL << i) * nc2(cnt1) % mod);
    }
    return ans;
}

ll sum_of_subset_ands(vector<ll> &a)
{
    ll ans = 0;
    for (ll i = 0; i < BITS; i++)
    {
        ll cnt1 = 0;
        for (ll j = 0; j < a.size(); j++)
        {
            if (a[j] & (1LL << i))
            {
                cnt1++;
            }
        }
        ans = addMod(ans, (1LL << i) * (powers_of_2[cnt1] - 1 + mod) % mod);
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    powers_of_2.resize(N);
    powers_of_2[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        powers_of_2[i] = addMod(powers_of_2[i - 1], powers_of_2[i - 1]);
    }
    ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    for (ll i = 0; i < BITS; i++)
    {
        ll cnt1 = 0;
        for (ll j = 0; j < n; j++)
        {
            if (a[j] & (1LL << i))
            {
                cnt1++;
            }
        }
        ll cnt0 = n - cnt1;
        ans1 = addMod(ans1, (1LL << i) * cnt0 % mod * cnt1 % mod);
        if (cnt1)
        {
            ans2 = addMod(ans2, (1LL << i) * powers_of_2[n - 1] % mod);
        }
        ans3 = addMod(ans3, (1LL << i) * nc2(cnt1) % mod);
        ans4 = addMod(ans4, (1LL << i) * (powers_of_2[cnt1] - 1 + mod) % mod);
    }

    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}