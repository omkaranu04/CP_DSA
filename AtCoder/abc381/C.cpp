#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    string s;
    cin >> n;
    cin >> s;
    ll ans = 1;
    for (int iter = 0; iter < n; iter++)
    {
        if (s[iter] != '/')
            continue;

        ll d = 0;
        while (true)
        {
            ll i = iter - (d + 1);
            ll j = iter + (d + 1);
            if (!(i >= 0 && i < n))
                break;
            if (!(j >= 0 && j < n))
                break;
            if (s[i] != '1')
                break;
            if (s[j] != '2')
                break;
            d++;
        }
        ans = max(ans, 2 * d + 1);
    }
    cout << ans << "\n";
    return 0;
}