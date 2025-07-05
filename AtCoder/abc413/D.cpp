#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
bool isgeom(vector<ll> &v, pair<ll, ll> &frac)
{
    if (v.size() <= 2)
    {
        frac = {1, 1};
        return true;
    }
    ll num = v[1], den = v[0];
    ll g = __gcd(num, den);
    num /= g;
    den /= g;
    frac = {num, den};

    for (ll i = 1; i < v.size(); i++)
    {
        ll lhs = v[i - 1] * num;
        ll rhs = v[i] * den;
        if (lhs != rhs)
            return false;
    }
    return true;
}
bool matches(vector<ll> &candi, map<ll, ll> &freq0)
{
    auto freq = freq0;
    for (auto x : candi)
    {
        auto it = freq.find(x);
        if (it == freq.end() || it->second == 0)
            return false;
        it->second--;
    }
    return true;
}
void solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N), absV;
    map<ll, ll> freq;
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
        freq[A[i]]++;
        absV.push_back(llabs(A[i]));
    }
    if (N <= 2)
    {
        cout << "Yes\n";
        return;
    }

    sort(absV.begin(), absV.end());
    pair<ll, ll> frac;
    bool ok = isgeom(absV, frac);
    if (!ok)
    {
        reverse(absV.begin(), absV.end());
        ok = isgeom(absV, frac);
    }
    if (!ok)
    {
        cout << "No\n";
        return;
    }
    vector<ll> candi(N);
    ll patt[4] = {1, -1, 1, -1};
    ll alt[4] = {0, 0, 1, 1};

    bool ans = false;
    for (ll p = 0; p < 4 && !ans; p++)
    {
        ll stsign = patt[p];
        bool alternate = alt[p];
        for (ll i = 0; i < N; i++)
        {
            ll s = stsign;
            if (alternate)
                s = (i & 1) ? -stsign : stsign;
            candi[i] = absV[i] * s;
        }
        ans = matches(candi, freq);
    }
    cout << (ans ? "Yes\n" : "No\n");
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