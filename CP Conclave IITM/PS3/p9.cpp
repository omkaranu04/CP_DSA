#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n, flag = 0;
        cin >> n;
        string arr[2 * n - 2];
        for (int i = 0; i < 2 * n - 2; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < 2 * n - 2; i++)
        {
            for (int j = i + 1; j < 2 * n - 2; j++)
            {
                if (size(arr[i]) == size(arr[j]))
                {
                    string s1 = arr[i];
                    string s2 = arr[j];
                    reverse(s2.begin(), s2.end());
                    if (s1 == s2)
                        flag++;
                    else
                        continue;
                }
            }
        }
        if (flag == n - 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
