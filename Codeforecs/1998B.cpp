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
        ll n;
        cin >> n;
        vector<ll> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i < n; i++)
        {
            cout << p[i] << " ";
        }
        cout << p[0] << endl;
    }
    return 0;
}