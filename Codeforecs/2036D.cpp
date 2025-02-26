#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll max_layers = min(n, m) / 2;
    vector<string> ans;
    for (int i = 0; i < max_layers; i++)
    {
        string temp = "";
        // left to right
        for (int j = i; j <= m - i - 1; j++)
            temp += a[i][j];
        // top to bottom
        for (int j = i + 1; j <= n - i - 2; j++)
            temp += a[j][m - i - 1];
        // right to left
        for (int j = m - i - 1; j >= i; j--)
            temp += a[n - i - 1][j];
        // bottom to top
        for (int j = n - i - 2; j >= i + 1; j--)
            temp += a[j][i];

        ans.push_back(temp);
    }
    // cout << endl;
    // for (auto i : a)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : ans)
    //     cout << i << " ";

    ll count = 0;
    for (auto s : ans)
    {
        ll n = s.length();
        for (int i = 0; i <= n - 1; i++)
        {
            if (s[i % n] == '1' && s[(i + 1) % n] == '5' && s[(i + 2) % n] == '4' && s[(i + 3) % n] == '3')
                count++;
        }
    }
    cout << count << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}