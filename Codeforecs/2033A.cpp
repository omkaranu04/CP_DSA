#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    ll curr_pos = 0;
    bool saku_chance = true;
    ll turn = 1;
    while (abs(curr_pos) < n)
    {
        if (saku_chance)
        {
            curr_pos -= (2 * turn - 1);
            saku_chance = false;
            turn++;
        }
        else
        {
            curr_pos += (2 * turn - 1);
            saku_chance = true;
            turn++;
        }
    }
    if (!saku_chance)
        cout << "Kosuke\n";
    else
        cout << "Sakurako\n";
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