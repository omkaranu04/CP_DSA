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
    for (ll i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
            cout << "Fizz";
        else
            cout << i;
        cout << endl;
    }
    return 0;
}