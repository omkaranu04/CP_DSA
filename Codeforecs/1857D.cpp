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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int c[n];
        for (int i = 0; i < n; i++)
        {
            c[i] = a[i] - b[i];
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, c[i]);
        }
        vector<int> strpnt;
        for (int i = 0; i < n; i++)
        {
            if (c[i] == maxi)
                strpnt.push_back(i + 1);
        }
        cout << strpnt.size() << endl;
        for (auto ele : strpnt)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}