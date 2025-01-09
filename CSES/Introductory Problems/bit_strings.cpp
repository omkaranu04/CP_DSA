#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int bin_exp(int a, int b)
{
    if (b == 0)
        return 1;
    int t = bin_exp(a, b / 2);
    if (b % 2)
        return (1LL * t * t % mod * a) % mod;
    return (1LL * t * t) % mod;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << bin_exp(2, n) << endl;
    return 0;
}