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
    ll n;
    cin >> n;
    if (n == 0)
        cout << 1 << endl;
    else
    {
        ll cyc[] = {8, 4, 2, 6};
        cout << cyc[(n - 1) % 4] << endl;
    }
    return 0;
}