#include <bits/stdc++.h>
using namespace std;
#define ll double

vector<pair<pair<ll, ll>, pair<ll, ll>>> pts;
int n, s, t;

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

ll simulate(vector<int> order, vector<int> directions)
{
    ll curr_x = 0, curr_y = 0;
    ll total_time = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = order[i];
        pair<ll, ll> start = directions[i] == 1 ? pts[idx].first : pts[idx].second;
        pair<ll, ll> end = directions[i] == 1 ? pts[idx].second : pts[idx].first;

        total_time += dist({curr_x, curr_y}, start) / s;

        total_time += dist(start, end) / t;

        curr_x = end.first;
        curr_y = end.second;
    }
    return total_time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s >> t;
    pts.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].first.first >> pts[i].first.second >> pts[i].second.first >> pts[i].second.second;
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    ll min_time = DBL_MAX;

    do
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            vector<int> directions(n);
            for (int i = 0; i < n; i++)
            {
                directions[i] = (mask & (1 << i)) ? 1 : 0;
            }
            min_time = min(min_time, simulate(order, directions));
        }
    } while (next_permutation(order.begin(), order.end()));

    cout << fixed << setprecision(25) << min_time << endl;
    return 0;
}
