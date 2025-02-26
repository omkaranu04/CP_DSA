#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int MaxSum = 0, MaxLength = 0;
    vector<int> subarr;
    int i = 0;
    while (i < n)
    {
        int sum = 0, length = 0;
        vector<int> curSub;
        // int j = i;
        if (a[i] > 0)
        {
            while (a[i] > 0 && i < n)
            {
                curSub.push_back(a[i]);
                sum += a[i];
                length++;
                i++;
            }

            if (sum > MaxSum || (sum == MaxSum && length > MaxLength))
            {
                MaxSum = sum;
                MaxLength = length;
                subarr = curSub;
            }
        }
        else
            i++;
    }
    for (auto ele : subarr)
    {
        cout << ele << " ";
    }
    return 0;
}