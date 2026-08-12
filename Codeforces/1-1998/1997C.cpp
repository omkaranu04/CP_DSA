#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> op_track;
    ll cost = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '_')
        {
            if (op_track.empty())
                s[i] = '(';
            else
                s[i] = ')';
        }

        if (s[i] == '(')
            op_track.push_back(i);
        else
        {
            cost += abs(i - op_track.back());
            op_track.pop_back();
        }
    }
    cout << cost << endl;
    return;
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