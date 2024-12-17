#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> k(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    multiset<ll> s;
    for (auto cube : k)
    {
        auto it = s.upper_bound(cube);
        if (it != s.end())
            s.erase(it);
        s.insert(cube);
    }
    cout << s.size() << endl;
    return 0;
}