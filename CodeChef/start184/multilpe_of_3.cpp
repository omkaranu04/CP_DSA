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
    if (n % 3 == 0)
        cout << n << endl;
    else if ((n + 1) % 3 == 0)
        cout << n + 1 << endl;
    else if ((n - 1) % 3 == 0)
        cout << n - 1 << endl;
    else if ((n + 2) % 3 == 0)
        cout << n + 2 << endl;
    else if ((n - 2) % 3 == 0)
        cout << n - 2 << endl;
    return 0;
}