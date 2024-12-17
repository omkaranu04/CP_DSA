#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    char a[n][4];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == '#')
                cout << j + 1 << " ";
        }
    }
    cout << endl;
    return;
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