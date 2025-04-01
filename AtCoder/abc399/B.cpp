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
    map<ll, vector<ll>, greater<ll>> m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        m[a].push_back(i);
    }
    vector<ll> rank(n, 0);
    ll curr_rank = 1;
    for (auto x : m)
    {
        vector<ll> temp = x.second;
        for (int i = 0; i < temp.size(); i++)
        {
            rank[temp[i]] = curr_rank;
        }
        curr_rank += temp.size();
    }
    for (int i = 0; i < n; i++)
    {
        cout << rank[i] << "\n";
    }
    return 0;
}