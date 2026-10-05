#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, V;
    cin >> N >> V;
    vector<ll> W(N + 1);
    for (ll i = 1; i <= N; i++)
        cin >> W[i];
    ll ans = 0;
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = 1; j <= N; j++)
        {
            for (ll k = 1; k <= N; k++)
            {
                if (i == j || j == k || k == i)
                    continue;
                if (i + j + k <= V)
                    ans = max(ans, W[i] + W[j] + W[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}