#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPrime(ll x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n1, n2;
        cin >> n1 >> n2;
        for (int i = n1; i <= n2; i++)
        {
            if (isPrime(i))
                cout << i << endl;
        }
        cout << endl;
    }
    return 0;
}