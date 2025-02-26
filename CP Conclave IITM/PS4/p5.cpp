#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int min = a[0], count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > min)
                count++;
        }
        cout << count << endl;
    }

    return 0;
}
