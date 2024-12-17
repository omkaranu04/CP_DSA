#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (m <= n && (n % 2 == m % 2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}