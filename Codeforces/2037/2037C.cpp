#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    if (n > 4)
    {
        for (int i = 2; i <= n; i += 2)
        {
            if (i != 4)
                cout << i << " ";
        }
        cout << 4 << " " << 5 << " ";
        for (int i = 1; i <= n; i += 2)
        {
            if (i != 5)
                cout << i << " ";
        }
        cout << endl;
        return;
    }
    cout << -1 << endl;
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