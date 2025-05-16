#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
vector<ll> len(51), patty(51);
// len of ith burger, number of patty in ith burger
void pre()
{
    len[0] = 1;
    patty[0] = 1;
    for (ll i = 1; i <= 50; i++)
    {
        len[i] = len[i - 1] * 2 + 3;
        patty[i] = patty[i - 1] * 2 + 1;
    }
}
ll func(ll level, ll x)
{
    if (level == 0)
        return x <= 0 ? 0 : 1;
    if (x == 1)
        return 0; // bottom is always a bun
    else if (x <= 1 + len[level - 1])
        return func(level - 1, x - 1);
    else if (x == 1 + len[level - 1] + 1)
        return patty[level - 1] + 1;
    else if (x <= 1 + len[level - 1] + 1 + len[level - 1])
        return patty[level - 1] + 1 + func(level - 1, x - 2 - len[level - 1]);
    else
        return patty[level];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    ll n, x;
    cin >> n >> x;
    cout << func(n, x) << endl;
    return 0;
}