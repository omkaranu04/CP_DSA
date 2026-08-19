#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll M, D;
    string S;
    cin >> M >> D >> S;
    vector<ll> watched(M + 1, 0);
    for (ll i = 0; i < M; i++)
    {
        if (S[i] == 'G')
        {
            ll l = max(0LL, i - D);
            ll r = min(M - 1, i + D);
            watched[l] += 1;
            watched[r + 1] -= 1;
        }
    }
    for(ll i=1;i<=M;i++) watched[i] += watched[i-1];
    ll ans = 0;
    for(ll i=0;i<M;i++) if(!watched[i]) ans++;
    cout<<ans;
    return 0;
}