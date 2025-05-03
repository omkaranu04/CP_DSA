#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;
ll fibo(ll a1, ll a2, ll a3, ll a4, ll a5)
{
    ll cnt = 0;
    if (a3 == a1 + a2)
        cnt++;
    if (a4 == a2 + a3)
        cnt++;
    if (a5 == a3 + a4)
        cnt++;
    return cnt;
}
void solve()
{
    ll a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;
    ll a31 = a1 + a2, a32 = a4 - a2, a33 = a5 - a4;
    ll a3, ans = 0;
    if (fibo(a1, a2, a31, a4, a5) >= ans)
    {
        a3 = a31;
        ans = fibo(a1, a2, a31, a4, a5);
    }
    if (fibo(a1, a2, a32, a4, a5) >= ans)
    {
        a3 = a32;
        ans = fibo(a1, a2, a32, a4, a5);
    }
    if (fibo(a1, a2, a33, a4, a5) >= ans)
    {
        a3 = a33;
        ans = fibo(a1, a2, a33, a4, a5);
    }
    // cout << "a3 : " << a3 << endl;
    v.push_back(fibo(a1, a2, a3, a4, a5));
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
    for (auto i : v)
        cout << i << endl;
    return 0;
}