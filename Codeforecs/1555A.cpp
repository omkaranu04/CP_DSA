#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, ans;
        cin >> n;
        if (n <= 6)
            ans = 15;
        else if (n > 6 && n % 2 == 0)
        {
            ans = (n * 5) / 2;
        }
        else if (n > 6 && n % 2 != 0)
        {
            ans = ((n + 1) * 5) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}
