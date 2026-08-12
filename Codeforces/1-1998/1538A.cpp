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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int maxPos = (max_element(a, a + n) - a) + 1;
        int minPos = (min_element(a, a + n) - a) + 1;
        int ans1 = minPos + (n - maxPos + 1);
        int ans2 = (n - minPos + 1) + maxPos;
        int ans3 = max(minPos, maxPos);
        int ans4 = n - min(maxPos, minPos) + 1;
        cout << min({ans1, ans2, ans3, ans4}) << endl;
    }
    return 0;
}