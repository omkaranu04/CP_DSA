#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    bool any_off = false;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            any_off = true;
    }
    // flips not allowed
    if (k == 0)
    {
        if (any_off)
            cout << "-1\n";
        else
            cout << "0\n";
        return;
    }
    //     ll current_flip_state = 0, all_flips_possible = 1;
    //     // current flip state is to track even or odd flips for current bulb
    //     ll ans = 0;
    //     vector<ll> flips(n, 0);
    //     for (ll i = 0; i < n; i++)
    //     {
    //         current_flip_state ^= flips[i];
    //         if (!(a[i] ^ current_flip_state)) // meaning that currently bulb is off so need to turn on
    //         {
    //             if (i + k - 1 < n)
    //             {
    //                 ans++;
    //                 current_flip_state ^= 1; // ho gya bulb on
    //                 flips[i + k] ^= 1;
    //             }
    //             else
    //                 all_flips_possible = 0;
    //         }
    //     }
    //     if (!all_flips_possible)
    //         ans = -1;
    //     cout << ans << "\n";
    vector<ll> ps(n + 1, 0);
    ll ans = 0, curr_sum = 0; // curr_sum for continuous flip tracking for every bulb
    for (ll i = 0; i < n; i++)
    {
        curr_sum += ps[i];
        if (a[i] == 0 && curr_sum % 2 == 1)
            continue;
        if (a[i] == 1 && curr_sum % 2 == 0)
            continue;
        ans++;
        ps[i] += 1;
        curr_sum++;
        if (i + k - 1 < n)
            ps[i + k] -= 1;
        else
        {
            cout << "-1\n";
            return;
        }
    }
    cout << ans << "\n";
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