#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == 'p')
            a[i] = 'q';
        else if (a[i] == 'q')
            a[i] = 'p';
    }
    cout << a << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}