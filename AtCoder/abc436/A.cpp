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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for (ll i = 0; i < n - s.length(); i++)
        cout << 'o';
    cout << s;
    return 0;
}