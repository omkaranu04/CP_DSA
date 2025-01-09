#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0' && i + 1 < s.size() && s[i + 1] == '0')
        {
            ans++;
            i++;
        }
        else
            ans++;
    }
    cout << ans << endl;
    return 0;
}