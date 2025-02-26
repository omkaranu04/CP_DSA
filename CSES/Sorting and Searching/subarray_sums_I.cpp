#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = 0;
    int curr_sum = 0;
    int ans = 0;
    while (r < n)
    {
        curr_sum += a[r];
        while (curr_sum > x && l <= r)
        {
            curr_sum -= a[l];
            l++;
        }
        if (curr_sum == x)
            ans++;
        r++;
    }
    cout << ans << endl;
    return 0;
}