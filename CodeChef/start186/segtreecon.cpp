#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
const int MAXH = 20;
vector<ll> tvals(20 + 1);
void solve()
{
    ll N, K;
    cin >> N >> K;
    ll L = (1LL << N);
    vector<ll> x(N + 1, 0);
    ll rem = K;
    for (ll h = N; h >= 0; h--)
    {
        ll tmp = tvals[h];
        ll cnt = rem / tmp;
        x[h] = cnt;
        rem -= cnt * tmp;
    }
    ll leaves_used = 0;
    for (ll h = 0; h <= N; h++)
        leaves_used += x[h] * (1LL << h);

    if (rem != 0 || leaves_used > L)
    {
        cout << "No\n";
        return;
    }
    vector<bool> used(L, false);
    string s(L, '0');
    bool ok = true;
    for (ll h = N; h >= 0; h--)
    {
        ll need = x[h];
        ll blk = 1 << h;
        ll seg = blk << 1;

        if (h == N)
        {
            if (need > 1)
            {
                ok = false;
                break;
            }
            if (need == 1)
            {
                for (ll i = 0; i < L; i++)
                {
                    used[i] = true;
                    s[i] = '1';
                }
            }
            continue;
        }

        for (ll base = 0; base < L; base += seg)
        {
            if (need == 0)
                break;
            bool can = true;
            for (ll i = base; i < base + blk; i++)
            {
                if (used[i])
                {
                    can = false;
                    break;
                }
            }
            if (can)
            {
                for (ll i = base; i < base + blk; i++)
                {
                    used[i] = true;
                    s[i] = '1';
                }
                need -= 1;
                continue;
            }

            ll rb = base + blk;
            can = true;
            for (ll i = rb; i < rb + blk; i++)
            {
                if (used[i])
                {
                    can = false;
                    break;
                }
            }
            if (can)
            {
                for (ll i = rb; i < rb + blk; i++)
                {
                    used[i] = true;
                    s[i] = '1';
                }
                need -= 1;
            }
        }
        if (need > 0)
        {
            ok = false;
            break;
        }
    }

    if (!ok)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        cout << s << endl;
    }
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 0; i < MAXH; i++)
    {
        tvals[i] = (1LL << (i + 1)) - 1;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}