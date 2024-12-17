#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll trial = 1;
        ll i = 0;
        ll count = 0;
        while (1)
        {
            if ((x & (trial << i)) == (y & (trial << i)))
            {
                count++;
            }
            else
                break;
            i++;
        }
        cout << (ll) pow(2, count) << endl;
    }
    return 0;
}