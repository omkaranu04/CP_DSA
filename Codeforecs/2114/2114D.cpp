#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        vector<pair<ll, int>> xs(n), ys(n);
        for (int i = 0; i < n; i++)
        {
            xs[i] = {x[i], i};
            ys[i] = {y[i], i};
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        ll x_min = xs.front().first;
        ll x_max = xs.back().first;
        ll y_min = ys.front().first;
        ll y_max = ys.back().first;
        ll ans = (x_max - x_min + 1) * (y_max - y_min + 1);

        ll x2_min = xs[1].first;
        ll x2_max = xs[n - 2].first;
        ll y2_min = ys[1].first;
        ll y2_max = ys[n - 2].first;

        vector<int> cand = {
            xs.front().second, xs.back().second,
            ys.front().second, ys.back().second};
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());

        for (int idx : cand)
        {
            ll xm = (idx == xs.front().second ? x2_min : x_min);
            ll xM = (idx == xs.back().second ? x2_max : x_max);
            ll ym = (idx == ys.front().second ? y2_min : y_min);
            ll yM = (idx == ys.back().second ? y2_max : y_max);

            ll w = xM - xm + 1;
            ll h = yM - ym + 1;
            ll area = w * h;

            if (area < n)
            {
                ll h_req = max(h, (n + w - 1) / w);
                ll a1 = w * h_req;
                ll w_req = max(w, (n + h - 1) / h);
                ll a2 = h * w_req;
                area = min(a1, a2);
            }
            ans = min(ans, area);
        }

        cout << ans << "\n";
    }
    return 0;
}
