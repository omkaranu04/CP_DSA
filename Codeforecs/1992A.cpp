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
        vector<ll> a(3);
        for (int i = 0; i < 3; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < 5; i++)
        {
            sort(a.begin(), a.end());
            a[0]++;
        }
        cout << a[0] * a[1] * 1ll * a[2] << endl;
    }
    return 0;
}