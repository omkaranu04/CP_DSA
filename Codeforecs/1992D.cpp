#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<ll> logs;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'L')
        {
            logs.push_back(i);
        }
    }
    logs.push_back(n + 1);
    ll loc = -1;
    ll next_log = 0;
    while (loc < n - 1)
    {
        if (loc + m >= logs[next_log])
        {
            loc = logs[next_log];
        }
        else
        {
            loc += m;
            if (loc > n - 1)
            {
                cout << "YES\n";
                return;
            }
            while (loc < n && loc < logs[next_log])
            {
                if (s[loc] != 'C' & k > 0)
                {
                    loc++;
                    k--;
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
        next_log++;
    }
    cout << "YES\n";
    return;
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