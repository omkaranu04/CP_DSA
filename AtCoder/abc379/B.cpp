#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0, curr = 0;
    for (auto i : s)
    {
        if (i == 'O')
            curr++;
        if (i == 'X')
            curr = 0;
        if (curr >= k)
        {
            ans++;
            curr = 0;
        }
    }
    cout << ans << endl;
    return 0;
}