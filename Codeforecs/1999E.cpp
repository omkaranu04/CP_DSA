#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    vector<bool> isPowerOf3(200001, false);
    ll iter = 3;
    isPowerOf3[1] = true;
    while (iter <= 200001)
    {
        isPowerOf3[iter] = true;
        iter *= 3;
    }
    vector<ll> divBy3(200001);
    ll count = 0;
    for (int i = 0; i < 200001; i++)
    {
        if (isPowerOf3[i])
            count++;
        divBy3[i] = count;
    }
    vector<ll> ps(200002);
    ps[0] = 0;
    for (int i = 1; i < 200002; i++)
    {
        ps[i] = ps[i - 1] + divBy3[i - 1];
    }
    // for (int i = 0; i < 20; i++)
    // {
    //     cout << divBy3[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < 20; i++)
    // {
    //     cout << ps[i] << " ";
    // }

    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        ans += 2 * divBy3[l];
        ans += (ps[r + 1] - ps[l + 1]);
        cout << ans << endl;
    }
    return 0;
}