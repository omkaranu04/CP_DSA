#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; i++)
        cin >> h[i];
    ll t = 0;
    for (ll i = 0; i < n; i++)
    {
        ll temp = h[i] / 5;
        t += 3 * temp;
        h[i] -= 5 * temp;
        while (h[i] > 0)
        {
            t++;
            if (t % 3 == 0)
                h[i] -= 3;
            else
                h[i]--;
        }
    }
    cout << t << endl;
    return 0;
}