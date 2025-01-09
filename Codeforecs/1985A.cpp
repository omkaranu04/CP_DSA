#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        string ans1 = b[0] + a.substr(1);
        string ans2 = a[0] + b.substr(1);
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}