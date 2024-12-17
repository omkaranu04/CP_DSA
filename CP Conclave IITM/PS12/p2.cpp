#include <bits/stdc++.h>
using namespace std;
const long long int M = 1000000007;
long long int modInv(long long int x, long long int n)
{
    if (n == 0)
        return 1;
    long long int res = modInv(x, n / 2);
    if (n % 2 == 0)
        return ((res % M) * (res % M)) % M;
    else
        return ((x % M) * (((res % M) * (res % M)) % M)) % M;
}
long long int fact(long long int n)
{
    long long int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial = ((factorial % M) * (i % M)) % M;
    }
    return factorial;
}
int main(int argc, char const *argv[])
{
    long long int n, r;
    cin >> n >> r;
    long long int num = fact(n);
    long long int den = ((fact(r) % M) * (fact(n - r) % M)) % M;
    long long int denOG = modInv(den, M - 2);
    cout << ((num % M) * (denOG % M)) % M << endl;
    return 0;
}