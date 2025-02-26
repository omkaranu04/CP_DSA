#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        string s;
        cin >> s;
        if (s.length() == i)
            ans++;
    }
    cout << ans << endl;
    return 0;
}