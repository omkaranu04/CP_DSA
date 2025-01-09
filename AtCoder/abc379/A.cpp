#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll c = n % 10;
    ll b = (n / 10) % 10;
    ll a = (n / 100) % 10;
    ll ans1 = b * 100 + c * 10 + a;
    ll ans2 = c * 100 + a * 10 + b;
    cout << ans1 << " " << ans2 << endl;
    return 0;
}