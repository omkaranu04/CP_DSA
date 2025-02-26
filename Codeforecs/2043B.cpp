#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, d;
    cin >> n >> d;
    cout << 1 << " ";
    if (n >= 3 || d % 3 == 0)
        cout << 3 << " ";
    if (d == 5)
        cout << 5 << " ";
    if (n >= 3 || d == 7)
        cout << 7 << " ";
    if (n >= 6 || d == 9 || (n >= 3 && d % 3 == 0))
        cout << 9 << " ";
    cout << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}