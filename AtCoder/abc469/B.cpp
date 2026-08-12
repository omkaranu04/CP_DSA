#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(int argc, char const *argv[])
{
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
            continue;

        if (i == 0)
        {
            if (n == 1 || s[i + 1] == 'x')
                ans++;
        }
        else if (i == n - 1)
        {
            if (s[i - 1] == 'x')
                ans++;
        }
        else
        {
            if (s[i - 1] == 'x' && s[i + 1] == 'x')
                ans++;
        }
    }
    cout << ans;
    return 0;
}