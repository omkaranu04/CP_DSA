#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b, d;
    cin >> a >> b >> d;
    while (a != b + d)
    {
        cout << a << " ";
        a += d;
    }
    return 0;
}