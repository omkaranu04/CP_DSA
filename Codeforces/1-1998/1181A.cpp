#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll x, y, z;
    cin >> x >> y >> z;
    ll ans1 = (x + y) / z;
    ll ans2;
    if (x % z + y % z >= z)
    {
        cout << (x / z) + (y / z) + 1 << " " << z - max(x % z, y % z) << endl;
    }
    else
    {
        cout << (x / z) + (y / z) << " " << 0 << endl;
    }
    return 0;
}