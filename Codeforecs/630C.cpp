#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    vector<ll> a(56, 0);
    ll k = 1;
    for (int i = 1; i < 56; i++)
    {
        k *= 2;
        a[i] = a[i - 1] + k;
    }
    ll n;
    cin >> n;
    cout << a[n] << endl;
    return 0;
}