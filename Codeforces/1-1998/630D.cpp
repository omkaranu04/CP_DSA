#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a = 6;
    ll d = 6;
    ll ans = n * a + (n * (n - 1) * d) / 2 + 1;
    cout << ans << endl;
    return 0;
}