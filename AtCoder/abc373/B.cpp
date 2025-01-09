#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> a(26);
    int ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        a[s[i] - 'A'] = i + 1;
    for (int i = 1; i < 26; i++)
    {
        ans += abs(a[i] - a[i - 1]);
    }
    cout << ans << endl;
    return 0;
}