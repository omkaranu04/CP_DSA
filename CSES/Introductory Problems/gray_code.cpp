#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = modpow(a, b / 2);
    if (b % 2)
        return t * t * a;
    return t * t;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    for (ll i = 0; i <= modpow(2, n); i++)
    {
        ll t = i;
        string s = "";
        while (t)
        {
            if (t % 2)
                s += '1';
            else
                s += '0';
            t /= 2;
        }
        cout << s << endl;
    }
    return 0;
}