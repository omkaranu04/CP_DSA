#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> even, odd;

    for (auto c : s)
    {
        if ((c - '0') % 2)
            odd.push_back(c);
        else
            even.push_back(c);
    }

    string ans = "";
    size_t i = 0, j = 0;

    while (i < even.size() && j < odd.size())
    {
        if (even[i] < odd[j])
            ans += even[i++];
        else
            ans += odd[j++];
    }

    while (i < even.size())
        ans += even[i++];
    while (j < odd.size())
        ans += odd[j++];

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
