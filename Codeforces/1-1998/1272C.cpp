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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> allowed(26, 0);
    for (ll i = 0; i < k; i++)
    {
        char x;
        cin >> x;
        allowed[x - 'a'] = 1;
    }
    ll ans = 0, i = 0;
    for (auto c : s)
    {
        if (allowed[c - 'a'])
        {
            i++;
            ans += i;
        }
        else
            i = 0;
    }
    cout << ans;
    return 0;
}