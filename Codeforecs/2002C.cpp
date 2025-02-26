#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> a;
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            a.push_back({x, y});
        }
        ll xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;
        vector<ll> distances;
        for (int i = 0; i < n; i++)
        {
            ll d = 1ll * (a[i].first - xt) * (a[i].first - xt) + 1ll * (a[i].second - yt) * (a[i].second - yt);
            distances.push_back(d);
        }
        ll std = 1ll * (xt - xs) * (xt - xs) + 1ll * (yt - ys) * (yt - ys);
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (distances[i] <= std)
                flag = false;
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}