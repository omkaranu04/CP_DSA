#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<ll> freq(26, 0);
    for (auto x : s)
        freq[x-'a']++;
    priority_queue<ll> pq;
    for (ll i = 0; i < 26; i++)
        if (freq[i])
            pq.push(freq[i]);
    while (m-- && !pq.empty())
    {
        ll top = pq.top();
        pq.pop();
        top--;
        if (top > 0)
            pq.push(top);
    }
    ll ans = 0;
    while (!pq.empty())
    {
        ll top = pq.top();
        pq.pop();
        ans += (top * 1LL * top);
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}