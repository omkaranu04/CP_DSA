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
        int a[n];
        for (int k = 0; k < n; k++)
        {
            cin >> a[k];
        }
        vector<int> even, odd;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                even.push_back(a[i]);
            else
                odd.push_back(a[i]);
        }
        // Sort the even and odd arrays separately.
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        // Merge the even and odd arrays back into 'a' array.
        int even_idx = 0, odd_idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < even.size())
                a[i] = even[even_idx++];
            else
                a[i] = odd[odd_idx++];
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (__gcd(a[i], 2 * a[j]) > 1)
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
