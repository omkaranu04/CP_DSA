#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (b > a)
            swap(a, b);
        if (d > c)
            swap(c, d);

        if ((c >= a || c <= b) && (d <= a && d >= b))
            cout
                << "YES" << endl;
        else if ((d >= a || d <= b) && (c <= a) && c >= b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}