#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxSize = 1e5 + 2;
vector<ll> bin, dp(maxSize);

int main(int argc, char const *argv[])
{
    bin.push_back(1);
    for (ll i = 0; i < bin.size(); i++)
    {
        if (bin[i] * 10 > maxSize)
            break;
        bin.push_back(bin[i] * 10);
        bin.push_back(bin[i] * 10 + 1);
    }

    dp[1] = 1;
    for (ll i = 2; i < maxSize; i++)
    {
        for (ll j = 0; j < bin.size(); j++)
        {
            dp[i] |= (i % bin[j] == 0) ? dp[i / bin[j]] : 0;
        }
    }

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        if (dp[n])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}