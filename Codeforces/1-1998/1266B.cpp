#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    vector<ll> x(t);
    for (int i = 0; i < t; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < t; i++)
    {
        ll op = x[i] % 14;
        ll og = x[i] / 14;
        if (og >= 1 && op >= 1 && op <= 6)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}