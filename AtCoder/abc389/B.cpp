#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x;
    cin >> x;
    ll n = 1;
    while (x != 1)
    {
        x /= n;
        n++;
    }
    cout << n - 1 << endl;
    return 0;
}