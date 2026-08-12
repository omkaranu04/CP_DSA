#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canBeSorted(const vector<int> &a)
{
    int n = a.size();
    if (is_sorted(a.begin(), a.end()))
    {
        return true;
    }

    int i = 0;
    while (i < n - 1 && a[i] <= a[i + 1])
    {
        i++;
    }

    int j = i + 1;
    while (j < n - 1 && a[j] <= a[j + 1])
    {
        j++;
    }

    if (j == n - 1 && a[j] <= a[0])
    {
        return true;
    }

    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        if (canBeSorted(a))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
