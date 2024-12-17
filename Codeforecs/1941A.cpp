#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> left(n), right(m);
        for (int i = 0; i < n; i++)
        {
            cin >> left[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> right[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (left[i] + right[j] <= k)
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}