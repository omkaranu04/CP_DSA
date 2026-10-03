#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    while (q--)
    {
        ll s, t;
        cin >> s >> t;
        if (s == t)
        {
            cout << 0 << endl;
            continue;
        }
        if ((s & t) == 0)
        {
            cout << s + t << endl;
            continue;
        }
        ll ans = LLONG_MAX;
        // s -> a -> t
        for (ll i = 0; i < 31; i++)
        {
            ll a = (1LL << i);
            if (a > n)
                continue;
            if ((s & a) == 0 && (a & t) == 0)
                ans = min(ans, s + a + a + t);
        }
        // s -> a -> b -> t
        vector<ll> A, B;
        for (ll i = 0; i < 31; i++)
        {
            ll tmp = (1LL << i);
            if (tmp > n)
                continue;
            if ((s & tmp) == 0)
                A.push_back(tmp);
            if ((t & tmp) == 0)
                B.push_back(tmp);
        }
        for (auto a : A)
        {
            for (auto b : B)
            {
                if (a == b)
                    continue;
                ll cost = (s + a) + (a + b) + (b + t);
                ans = min(ans, cost);
            }
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    }
    return 0;
}