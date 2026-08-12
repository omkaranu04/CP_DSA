#include <bits/stdc++.h>
using namespace std;

vector<int> gcd_1[1001];

int main(int argc, char const *argv[])
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            if (__gcd(i, j) == 1)
            {
                gcd_1[i].push_back(j);
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> index[1001];
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            index[x].push_back(i);
        }
        int answer = -1;

        for (int i = 1; i <= 1000; i++)
        {
            for (auto j : gcd_1[i])
                if (!index[i].empty() && !index[j].empty())
                {
                    answer = max(answer, index[i].back() + index[j].back());
                }
        }
        cout << answer << endl;
    }
    return 0;
}