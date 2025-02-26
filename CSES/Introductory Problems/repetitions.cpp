#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll count = 1, max_count = 1;
    for (ll i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
            max_count = max(max_count, count);
        }
        else
        {
            count = 1;
        }
    }
    cout << max_count << endl;
    return 0;
}