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
    double a, b;
    cin >> a >> b;
    if (a + b == 9.0 || a - b == 9.0 || a * b == 9.0 || a / b == 9.0)
        cout << "Nine";
    else
        cout << "Nein";
    return 0;
}