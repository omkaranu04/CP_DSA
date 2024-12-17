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
    ll n;
    cin >> n;
    if (isPrime(n))
        cout << 1 << endl;
    else if ((n % 2 == 0) || isPrime(n - 2))
        cout << 2;
    else
        cout << 3;
    return 0;
}