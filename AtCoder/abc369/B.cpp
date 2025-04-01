#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    ll posx = -1, posy = -1;
    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        ll x;
        char c;
        cin >> x >> c;
        if (c == 'L')
        {
            if (posx != -1)
                ans += abs(x - posx);
            posx = x;
        }
        else
        {
            if (posy != -1)
                ans += abs(x - posy);
            posy = x;
        }
    }
    cout << ans << endl;
    return 0;
}