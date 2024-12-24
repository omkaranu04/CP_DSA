#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll comp(pair<ll, string> a, pair<ll, string> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<ll> a(5);
    for (ll i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    vector<pair<ll, string>> p;
    string s = "ABCDE";
    ll tot = (1 << 5);
    for (ll i = 1; i < tot; i++)
    {
        string temp;
        ll score = 0;
        for (ll j = 0; j < 5; j++)
        {
            if (i & (1 << j))
            {
                temp += s[j];
                score += a[j];
            }
        }
        p.push_back({score, temp});
    }
    sort(p.begin(), p.end(), comp);
    for (auto i : p)
    {
        cout << i.second << "\n";
    }
    return 0;
}