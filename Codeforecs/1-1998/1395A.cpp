#include <iostream>
using namespace std;

typedef long long int ll;

bool check(ll r, ll g, ll b, ll w)
{
    return (r % 2 + g % 2 + b % 2 + w % 2) > 1 ? false : true;
}

int main()
{
    ll T;
    cin >> T;
    for (ll ttt = 0; ttt < T; ++ttt)
    {
        ll r, g, b, w;
        cin >> r >> g >> b >> w;
        if (check(r, g, b, w))
        {
            cout << "Yes" << endl;
        }
        else if (r > 0 && g > 0 && b > 0 && check(r - 1, g - 1, b - 1, w + 1))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
