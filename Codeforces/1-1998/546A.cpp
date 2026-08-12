#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll k, n, w;
    cin >> k >> n >> w;
    ll cost = 0;
    for (int i = 1; i <= w; i++)
    {
        cost += (k * i);
    }
    if (cost <= n)
        cout << 0 << endl;
    else
        cout << cost - n << endl;
    return 0;
}
