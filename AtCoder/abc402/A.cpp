#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, ans = "";
    cin >> s;
    for (auto x : s)
    {
        if (x >= 'A' && x <= 'Z')
            ans += x;
    }
    cout << ans << endl;
    return 0;
}