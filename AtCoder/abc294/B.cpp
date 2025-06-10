#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll h, w;
    cin >> h >> w;
    for (ll i = 1; i <= h; i++)
    {
        for (ll j = 1; j <= w; j++)
        {
            ll x;
            cin >> x;
            if (x == 0)
                cout << ".";
            else
                cout << (char)('A' + x - 1);
        }
        cout << endl;
    }
    return 0;
}