#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> alpha(26, -1);
    for (int i = 0; i < s.length(); i++)
    {
        int curr = (s[i] - 'a');
        if (alpha[curr] == -1)
            alpha[curr] = (i % 2);
        else
        {
            if (alpha[curr] != (i % 2))
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}