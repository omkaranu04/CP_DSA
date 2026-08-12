#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll count = 0;
    ll diag = n - 1;
    if (k >= n)
    {
        count++;
        k -= n;
    }
    while (k > 0)
    {
        if (k >= diag)
        {
            count++;
            k -= diag;
        }
        if (k >= diag)
        {
            count++;
            k -= diag;
        }
        diag--;
    }
    cout << count << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}