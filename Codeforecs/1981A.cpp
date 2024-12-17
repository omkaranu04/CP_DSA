#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = 1;
        ll score = 0;
        while (ans <= r)
        {
            ans = ans << 1;
            score++;
        }
        score--;
        cout << score << endl;
    }
    return 0;
}