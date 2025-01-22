#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<char> b(m);
    for (ll i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    vector<bool> ac(n, false);
    for (ll i = 0; i < m; i++)
    {
        if (b[i] == 'M')
        {
            if (!ac[a[i] - 1])
            {
                ac[a[i] - 1] = true;
                cout << "Yes\n";
            }
            else
                cout << "No\n";
        }
        else
            cout << "No\n";
    }
    return 0;
}