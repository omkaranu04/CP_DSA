#include <bits/stdc++.h>
using namespace std;
long long int SumOfDigits(long long int n)
{
    long long int sum = 0;
    while (n != 0)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long int n;
        cin >> n;
        while (__gcd(n, SumOfDigits(n)) < 2)
        {
            ++n;
        }
        cout << n << endl;
    }
    return 0;
}
