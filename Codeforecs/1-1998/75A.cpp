#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll removeZeros(ll n)
{
    ll val = 0, rem, placeval = 1;
    while (n > 0)
    {
        rem = n % 10;
        if (rem)
        {
            val = val + rem * placeval;
            placeval *= 10;
        }
        n = n / 10;
    }
    return val;
}

int main(int argc, char const *argv[])
{
    ll a, b, c;
    cin >> a >> b;
    c = a + b;

    a = removeZeros(a);
    b = removeZeros(b);
    c = removeZeros(c);

    if (a + b == c)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
