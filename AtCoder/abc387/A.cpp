#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    ll ans = (a + b) * (a + b);
    cout << ans << endl;
    return 0;
}