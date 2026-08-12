#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int sum = (n * (n + 1)) / 2;
        long long int pow2 = 1;
        while (pow2 <= n)
        {
            sum -= pow2 * 2;
            pow2 = pow2 * 2;
        }
        cout << sum << endl;
    }
    return 0;
}