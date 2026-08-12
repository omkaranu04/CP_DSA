#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        int height[n];
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
            sum += height[i];
        }
        if (sum % n == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
