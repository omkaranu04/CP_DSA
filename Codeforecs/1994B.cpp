#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    if (n == 1)
    {
        if (s == "0" && t == "1")
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        return;
    }
    int index = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        if (s == t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < index; i++)
    {
        if (t[i] == '1')
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
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