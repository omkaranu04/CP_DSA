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
    ll n;
    cin >> n;
    string t, a;
    cin >> t;
    cin >> a;
    bool x = false;
    for (ll i = 0; i < n; i++)
    {
        if (t[i] == a[i] && t[i] == 'o')
            x = true;
    }
    if (x)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}