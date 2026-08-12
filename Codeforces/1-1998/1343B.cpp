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
        if (n % 4 != 0)
            cout << "NO" << endl;
        else
        {
            vector<int> ans;
            for (int i = 1; i <= n / 2; i++)
            {
                ans.push_back(2 * i);
            }
            for (int i = 1; i <= n / 2; i++)
            {
                if (i == n / 2)
                {
                    ans.push_back(2 * i - 1 + n / 2);
                }
                else
                {
                    ans.push_back(2 * i - 1);
                }
            }
            cout << "YES" << endl;
            for (auto i : ans)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}