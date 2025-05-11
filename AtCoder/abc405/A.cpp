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
    ll r, x;
    cin >> r >> x;
    if (x == 1 && (r >= 1600 && r <= 2999))
        cout << "Yes\n";
    else if (x == 2 && (r >= 1200 && r <= 2399))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}