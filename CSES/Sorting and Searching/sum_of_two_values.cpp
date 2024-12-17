#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> num_with_indices;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        num_with_indices.push_back({a, i + 1});
    }
    sort(num_with_indices.begin(), num_with_indices.end());
    ll i = 0, j = n - 1;
    while (i < j)
    {
        ll sum = num_with_indices[i].first + num_with_indices[j].first;
        if (sum == x)
        {
            cout << num_with_indices[i].second << " " << num_with_indices[j].second << endl;
            return 0;
        }
        else if (sum < x)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}