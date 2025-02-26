#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1000005;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> divisors(N, 0);
    for (ll i = 1; i <= N; i++)
    {
        for (ll j = i; j <= N; j += i)
            divisors[j]++;
    }
    ll n;
    cin >> n;
    while (n--)
    {
        ll x;
        cin >> x;
        cout << divisors[x] << endl;
    }
    return 0;
}