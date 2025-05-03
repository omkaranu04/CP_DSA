#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int total_drink = k * l;
    int total_slices = c * d;
    int s_total_drink = total_drink / nl;
    int s_total_slices = total_slices;
    int s_salt = p / np;
    int ans = min(min(s_total_drink, s_total_slices), s_salt) / n;
    cout << ans << endl;
    return 0;
}