#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll solve(ll n)
{
    if (n == 0)
        return 0;
    return n / 5 + solve(n / 5);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}