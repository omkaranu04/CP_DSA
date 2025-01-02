#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; i++)
        cin >> H[i];
    ll ans = 1;
    for (ll start = 0; start < N; start++)
    {
        for (ll interval = 1; start + interval <= N; interval++)
        {
            ll tans = 0, height = H[start], curr = 1;
            for (ll i = start + interval; i < N; i += interval)
            {
                if (H[i] == height)
                {
                    curr++;
                    tans = max(tans, curr);
                }
                else
                    break;
            }
            ans = max(ans, tans);
        }
    }
    cout << ans << endl;
    return 0;
}