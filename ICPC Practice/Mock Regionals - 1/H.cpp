#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> cnt(32, 0);
    for (ll i = 0; i <= 31; i++)
    {
        for (auto &x : a)
        {
            if (x & (1LL << i))
                cnt[i]++;
        }
    }
    ll flag = -1;
    for (ll i = 31; i >= 0; i--)
    {
        ll cnt1 = cnt[i];
        ll cnt0 = n - cnt1;
        if (cnt1 % 2 == 1 && cnt0 % 2 == 0)
        {
            if (cnt1 % 4 == 3)
            {
                cout << "LOSE\n";
                return;
            }
            else
            {
                cout << "WIN\n";
                return;
            }
        }
        if (cnt1 % 2 == 1 && cnt0 % 2 == 1)
        {
            if (cnt1 % 4 == 3)
            {
                cout << "WIN\n";
                return;
            }
            if (cnt1 % 4 == 1)
            {
                cout << "WIN\n";
                return;
            }
        }
    }
    cout << "DRAW\n";
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}