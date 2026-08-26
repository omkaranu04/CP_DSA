#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    if (n >= m)
    {
        cout << n - m << '\n';
        return 0;
    }
    while (m > n)
    {
        if (m % 2 == 0)
            m /= 2;
        else
            m++;
        ans++;
    }
    ans += n - m;
    cout << ans << '\n';
    return 0;
}