#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a;
    cin >> a;
    if (400 % a != 0)
        cout << -1 << endl;
    else
        cout << 400 / a << endl;
    return 0;
}