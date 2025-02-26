#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        map<char, ll> charToNum;
        map<ll, char> numToChar;
        string s;
        cin >> s;

        if (s.size() != n)
        {
            cout << "NO" << endl;
            continue;
        }

        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            char c = s[j];
            ll num = a[j];

            if (charToNum.find(c) != charToNum.end())
            {
                if (charToNum[c] != num)
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                charToNum[c] = num;
            }

            if (numToChar.find(num) != numToChar.end())
            {
                if (numToChar[num] != c)
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                numToChar[num] = c;
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
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