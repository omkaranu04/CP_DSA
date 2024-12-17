#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    ll nb, ns, nc;
    cin >> nb >> ns >> nc;
    ll pb, ps, pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;

    ll cb = 0, cs = 0, cc = 0;
    for (char c : s)
    {
        if (c == 'B')
            cb++;
        if (c == 'S')
            cs++;
        if (c == 'C')
            cc++;
    }

    ll left = 0;
    ll right = r + nb + ns + nc;

    auto canMake = [&](ll x)
    {
        ll cost = (max(0LL, x * cb - nb)) * pb +
                  (max(0LL, x * cs - ns)) * ps +
                  (max(0LL, x * cc - nc)) * pc;
        return cost <= r;
    };

    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (canMake(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << right << endl;
    return 0;
}
