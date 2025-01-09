#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n], b[n];
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                a[i]++;
                if (a[i] == n)
                    a[i] = 0;
            }
            else
            {
                a[i]--;
                if (a[i] == -1)
                    a[i] = n - 1;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                count++;
        }
        if (count == n)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
