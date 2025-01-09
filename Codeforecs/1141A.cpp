#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    if (m % n != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int count = 0;
    m = m / n;
    while (m % 2 == 0)
    {
        m /= 2;
        count++;
    }
    while (m % 3 == 0)
    {
        m /= 3;
        count++;
    }
    if (m == 1)
        cout << count << endl;
    else
        cout << -1 << endl;
    return 0;
}