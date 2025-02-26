#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(a[i]) != mp.end())
        {
            cout << mp[a[i]] + 1 << " ";
        }
        else
            cout << -1 << " ";
        mp[a[i]] = i;
    }
}