#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int M;
ll modInv(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll res = modInv(x, n / 2);
    if (n % 2 == 0)
        return ((res % M) * (res % M)) % M;
    else
        return ((x % M) * (((res % M) * (res % M)) % M)) % M;
}
int main(int argc, char const *argv[])
{
    ll n, x;
    cin >> n >> x;
    M = x;
    cout << modInv(n, x - 2) % x << endl;
    return 0;
}