#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<string> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    set<string> s;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            string tmp = a[i] + a[j];
            s.insert(tmp);
        }
    }
    cout << s.size();
    return 0;
}