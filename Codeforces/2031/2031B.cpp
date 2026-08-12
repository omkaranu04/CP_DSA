#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canSortWithSwaps(vector<int> &p, int n)
{
    int i = 1;
    while (i <= n)
    {
        if (p[i] != i)
        {
            if (i - 1 >= 1 && p[i - 1] == i && abs(p[i] - p[i - 1]) == 1)
            {
                swap(p[i], p[i - 1]);
            }
            else if (i + 1 <= n && p[i + 1] == i && abs(p[i] - p[i + 1]) == 1)
            {
                swap(p[i], p[i + 1]);
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> p[i];
        }
        if (canSortWithSwaps(p, n))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
