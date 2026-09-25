#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll N;
        cin >> N;
        vector<ll> p(N);
        for (auto &x : p)
            cin >> x;
        ll minl = LLONG_MAX, maxl = LLONG_MIN;
        ll minr = LLONG_MAX, maxr = LLONG_MIN;
        for (ll i = 0; i < N / 2; i++)
        {
            minl = min(minl, p[i]);
            maxl = max(maxl, p[i]);
        }
        for (ll i = N / 2; i < N; i++)
        {
            minr = min(minr, p[i]);
            maxr = max(maxr, p[i]);
        }
        if (maxl < minr || minl > maxr)
        {
            cout << 1 << endl;
            cout << N << " ";
            for (auto x : p)
                cout << x << " ";
            cout << endl;
            continue;
        }

        vector<ll> sl, bl, sr, br;
        for (ll i = 0; i < N / 2; i++)
        {
            if (p[i] <= N / 2)
                sl.push_back(p[i]);
            else
                bl.push_back(p[i]);
        }
        for (ll i = N / 2; i < N; i++)
        {
            if (p[i] <= N / 2)
                sr.push_back(p[i]);
            else
                br.push_back(p[i]);
        }
        cout << 2 << endl;
        cout << sl.size() + br.size() << " ";
        for (auto x : sl)
            cout << x << " ";
        for (auto x : br)
            cout << x << " ";
        cout << endl
             << bl.size() + sr.size() << " ";
        for (auto x : bl)
            cout << x << " ";
        for (auto x : sr)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}