#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int g = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            cout << a[i] / 2 << endl;
        else
        {
            cout << (a[i] + g) / 2 << endl;
            ;
            g *= -1;
        }
    }
    return 0;
}