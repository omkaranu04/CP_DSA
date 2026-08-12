#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll r = n, l = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            cout << l << " ";
            l++;
        }
        else
        {
            cout << r << " ";
            r--;
        }
    }
    cout << endl;
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