#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll X;
    cin >> X;
    if (X == 1)
        cout << 2;
    else if (X == 2)
        cout << 3;
    else if (X == 3)
        cout << 1;
    return 0;
}