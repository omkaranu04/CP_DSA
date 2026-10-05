#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, Q;
    cin >> N >> Q;
    vector<vector<pair<ll, ll>>> intervals(Q + 1);
    for (ll i = 1; i <= Q; i++)
    {
        ll L, R, X;
        cin >> L >> R >> X;
        intervals[X].push_back({L, R});
    }
    vector<ll> diff(N + 2, 0);
    for (ll i = 1; i <= Q; i++)
    {
        auto &v = intervals[i];
        if (v.empty())
            continue;
        sort(v.begin(), v.end());
        ll currL = v[0].first, currR = v[0].second;
        for (ll j = 1; j < v.size(); j++)
        {
            ll L = v[j].first, R = v[j].second;
            if (L <= currR)
                currR = max(currR, R);
            else
            {
                diff[currL]++;
                diff[currR + 1]--;
                currL = L;
                currR = R;
            }
        }
        diff[currL]++;
        diff[currR + 1]--;
    }
    ll curr = 0;
    for (ll i = 1; i <= N; i++)
    {
        curr += diff[i];
        cout << curr << " ";
    }
    return 0;
}
