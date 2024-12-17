#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a[3], poscount = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j];
            if (a[j] == 1)
                poscount++;
        }
        if (poscount >= 2)
            count++;
    }
    cout << count << endl;
    return 0;
}
