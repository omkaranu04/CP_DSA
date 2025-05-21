#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll num = 0;
    for (ll i = 0; i < n; i++)
    {
        num = (num * 2 + (s[i] - '0')) % k;
    }
    if (num == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
