#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = (7 - a) + (7 - b) + (7 - c);
    cout << ans << endl;
    return 0;
}