#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, string>> ss(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> ss[i].second;
        ss[i].first = ss[i].second.length();
    }
    sort(ss.begin(), ss.end());
    for (ll i = 0; i < n; i++)
    {
        cout << ss[i].second;
    }
    return 0;
}