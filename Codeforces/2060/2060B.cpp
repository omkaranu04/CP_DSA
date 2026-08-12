#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> cards(n);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        vector<ll> temp(m);
        for (int j = 0; j < m; j++)
            cin >> temp[j];
        sort(temp.begin(), temp.end());
        cards[i] = {temp[0] % n, i};
        ll f_card = temp[0] % n;
        for (int j = 1; j < m; j++)
        {
            if (temp[j] % n != f_card)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag == false)
        cout << "-1\n";
    else
    {
        sort(cards.begin(), cards.end());
        for (int i = 0; i < n; i++)
            cout << cards[i].second + 1 << " ";
        cout << endl;
    }
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