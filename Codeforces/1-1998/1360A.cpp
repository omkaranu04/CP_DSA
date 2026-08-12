#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = min(max(2 * a, b), max(a, 2 * b));
        cout << ans * ans << endl;
    }
    return 0;
}