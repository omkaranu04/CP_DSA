#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> x(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x[i];
        }

        vector<int> a(n);
        a[0] = 1000;

        for (int i = 1; i < n; i++)
        {
            a[i] = a[i - 1] + x[i - 1];
        }
        for (auto i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}