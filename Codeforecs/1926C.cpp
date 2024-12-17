#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll sum(ll x)
{
    ll sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    ll res[200001];
    res[0] = 0;
    for (int i = 1; i < 200001; i++)
    {
        res[i] = res[i - 1] + sum(i);
    }
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}