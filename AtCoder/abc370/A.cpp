#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll l, r;
    cin >> l >> r;
    if (l == 1 && r == 0)
        cout << "Yes\n";
    else if (r == 1 && l == 0)
        cout << "No\n";
    else
        cout << "Invalid\n";
    return 0;
}