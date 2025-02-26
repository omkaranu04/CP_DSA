#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for (auto i : a)
    {
        cout << i.first << " " << i.second << endl;
    }
    
    return 0;
}