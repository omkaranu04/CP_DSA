#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= 26; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            for (int k = 1; k <= 26; k++)
            {
                if (i + j + k == n)
                {
                    string s = "";
                    s += (char)(i + 96);
                    s += (char)(j + 96);
                    s += (char)(k + 96);
                    cout << s << endl;
                    return;
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}