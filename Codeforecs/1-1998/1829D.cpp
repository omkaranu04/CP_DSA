#include <bits/stdc++.h>
using namespace std;
bool can_make(int n, int m)
{
    if (n == m)
        return true;
    else if (n % 3 != 0)
        return false;
    else
    {
        bool ans = (can_make(n / 3, m) || can_make((2 * n) / 3, m));
        return ans;
    }
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (can_make(n, m))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}