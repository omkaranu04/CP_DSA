#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n, s, m;
    cin >> n >> s >> m;

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end());

    if (tasks[0].first >= s)
    {
        cout << "YES" << endl;
        return;
    }

    bool canShower = false;
    for (int i = 1; i < n; ++i)
    {
        if (tasks[i].first - tasks[i - 1].second >= s)
        {
            canShower = true;
            break;
        }
    }
    
    if (m - tasks[n - 1].second >= s)
    {
        canShower = true;
    }

    if (canShower)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}