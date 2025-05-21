#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
set<ll> tmp;
string convtostring(ll n)
{
    string ret = "";
    while (n)
    {
        ret += char('0' + (n % 2));
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

ll convtonum(const string &s)
{
    ll ret = 0;
    for (char c : s)
    {
        ret = (ret << 1) + (c - '0');
    }
    return ret;
}
void make(ll h, ll hl, ll maxlen)
{
    string half = convtostring(h);
    while ((ll)half.size() < hl)
        half.insert(half.begin(), '0');
    string rev = half.substr(0, maxlen % 2 ? hl - 1 : hl);
    reverse(rev.begin(), rev.end());
    string s = half + rev;
    ll num = convtonum(s);
    tmp.insert(num);
}
void solve()
{
    tmp.clear();
    ll N;
    cin >> N;
    string s = convtostring(N);
    ll ns = s.size();
    ll hl = (ns + 1) / 2;

    ll h = 0;
    for (ll i = 0; i < hl; i++)
        h = (h << 1) + (s[i] - '0');

    for (ll i = h - 1; i <= h + 1; i++)
        if (i > 0)
            make(i, hl, ns);

    if (ns > 1)
        tmp.insert((1LL << (ns - 1)) - 1);
    tmp.insert((1LL << ns) | 1LL);

    ll ans = 1e18;
    for (auto x : tmp)
        ans = min(ans, llabs(x - N));

    cout << ans << endl;
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