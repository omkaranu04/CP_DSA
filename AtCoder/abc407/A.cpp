#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B;
    cin >> A >> B;
    ll x = A / B;
    if (A % B == 0)
        cout << x;
    else
    {
        long double xx = (long double)A / B;
        long double diff1 = abs(xx - x);
        long double diff2 = abs(xx - (x + 1));
        if (diff1 < diff2)
            cout << x << endl;
        else
            cout << x + 1 << endl;
    }
    return 0;
}