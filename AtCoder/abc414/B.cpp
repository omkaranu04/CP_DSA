#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N;
    cin >> N;
    string ans = "";
    ll l = 0;
    for (ll i = 0; i < N; i++)
    {
        char c;
        ll t;
        cin >> c >> t;
        l += t;
        if (l > 100)
        {
            cout << "Too Long\n";
            return 0;
        }
        ans += string(t, c);
    }
    cout << ans << endl;
    return 0;
}