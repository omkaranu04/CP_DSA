#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    if ((a + b == c) || (a + c == b) || (b + c == a) || ((a == b) && (b == c)))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}