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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int even_shit = 0, odd_shit = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != i % 2)
            {
                if (i % 2)
                    odd_shit++;
                else
                    even_shit++;
            }
        }
        if (even_shit == odd_shit)
            cout << even_shit << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}