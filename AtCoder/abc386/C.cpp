#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll k;
    string s, t;
    cin >> k >> s >> t;
    if (s == t)
    {
        cout << "Yes\n";
    }
    else if (s.length() == t.length())
    {
        ll change = 0;
        for (ll i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                change++;
            }
        }
        if (change <= 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else if (s.length() + 1 == t.length())
    {
        ll i = 0, j = 0;
        while (i < s.length())
        {
            if (s[i] == t[i])
                i++;
            else
                break;
        }
        while (j < s.length())
        {
            if (s[s.length() - j - 1] == t[t.length() - j - 1])
                j++;
            else
                break;
        }
        if (i + j >= s.length())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else if (s.length() - 1 == t.length())
    {
        ll i = 0, j = 0;
        while (i < t.length())
        {
            if (s[i] == t[i])
                i++;
            else
                break;
        }
        while (j < t.length())
        {
            if (s[s.length() - j - 1] == t[t.length() - j - 1])
                j++;
            else
                break;
        }
        if (i + j >= t.length())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}