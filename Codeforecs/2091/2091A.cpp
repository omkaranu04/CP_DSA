#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll zero = 0, one = 0, two = 0, three = 0, five = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            zero++;
        if (a[i] == 1)
            one++;
        if (a[i] == 2)
            two++;
        if (a[i] == 3)
            three++;
        if (a[i] == 5)
            five++;
        if (zero >= 3 && one >= 1 && two >= 2 && three >= 1 && five >= 1)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
    return;
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