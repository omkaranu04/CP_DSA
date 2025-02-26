#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, pair<int, int>> mp;
    mp[a[0] + a[1]] = {0, 1};
    for (int i = 2; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = a[i] + a[j];
            if (mp.find(x - temp) != mp.end())
            {
                cout << "YES\n";
                return 0;
            }
        }
        for (int j = 0; j < i; j++)
        {
            mp[a[i] + a[j]] = {i, j};
        }
    }
    cout << "NO\n";
    return 0;
}