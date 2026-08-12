#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int m, n;
    cin >> n >> m;
    int a, b, count = 0;
    for (a = 0; a <= n && a <= m; a++)
    {
        for (b = 0; b <= n && b <= m; b++)
        {
            if ((a * a + b == n) && (a + b * b == m))
                count++;
        }
    }
    cout << count << endl;
    return 0;
}
