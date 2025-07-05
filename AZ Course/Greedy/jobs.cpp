#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> jobs(n); // dead, dur
    for (ll i = 0; i < n; i++)
        cin >> jobs[i].first;
    for (ll i = 0; i < n; i++)
        cin >> jobs[i].second;

    sort(jobs.begin(), jobs.end());
    ll curr = 0, ans = 0;
    priority_queue<ll> pq;
    for (ll i = 0; i < n; i++)
    {
        ll dead = jobs[i].first, dur = jobs[i].second;
        if (curr + dur <= dead)
        {
            curr += dur;
            pq.push(dur);
        }
        else if (!pq.empty() && pq.top() > dur)
        {
            curr -= pq.top();
            pq.pop();
            curr += dur;
            pq.push(dur);
        }
    }
    cout << pq.size() << endl;
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