#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    int l = 0, r = n - 1, ans = 0;
    while (l < r)
    {
        int cap = min(height[l], height[r]) * (r - l);
        ans = max(ans, cap);
        if (height[l] > height[r])
            r--;
        else
            l++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> height[i];
    }

    int result = maxArea(height);
    cout << result << endl;

    return 0;
}
