#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), freq(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    // if (n == 1)
    // {
    //     cout << 1 << " " << 1 << endl;
    //     return;
    // }
    vector<ll> len(n + 1);
    len[0] = (freq[a[0]] == 1);
    for (int i = 1; i < n; i++)
    {
        if (freq[a[i]] == 1)
            len[i] = len[i - 1] + 1;
    }
    ll ans_max = *max_element(len.begin(), len.end());
    if (ans_max == 0)
    {
        // cout << "ans : ";
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (len[i] == ans_max)
        {
            // cout << "ans : ";
            cout << i - len[i] + 2 << " " << i + 1 << endl;
            return;
        }
    }
    return;
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