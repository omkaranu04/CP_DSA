#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int sum = 0, overallSmallest = INT_MAX;
        vector<int> secondSmallest;
        while (n--)
        {
            long long int m;
            cin >> m;
            long long int a[m];
            for (int i = 0; i < m; i++)
            {
                cin >> a[i];
                if (a[i] < overallSmallest)
                    overallSmallest = a[i];
            }
            sort(a, a + m);
            reverse(a, a + m);
            secondSmallest.push_back(a[m - 2]);
        }
        sum = sum + overallSmallest;
        sort(secondSmallest.begin(), secondSmallest.end());
        for (int i = 1; i < secondSmallest.size(); i++)
        {
            sum += secondSmallest[i];
        }
        cout << sum << endl;
    }
    return 0;
}