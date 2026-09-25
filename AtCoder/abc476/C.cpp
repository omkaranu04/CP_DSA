#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll first = 0, second = 0, third = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x >= first)
        {
            third = second;
            second = first;
            first = x;
        }
        else if (x >= second)
        {
            third = second;
            second = x;
        }
        else if (x > third)
        {
            third = x;
        }
        if (i >= 2)
            cout << third << endl;
    }
    return 0;
}