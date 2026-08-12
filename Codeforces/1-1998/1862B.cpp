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
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<int> a;
        a.push_back(b[0]);
        for (int i = 1; i < n; i++)
        {
            if (b[i - 1] > b[i])
            {
                a.push_back(b[i]);
                a.push_back(b[i]);
            }
            else
            {
                a.push_back(b[i]);
            }
        }
        cout << a.size() << endl;
        for (auto ele : a)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}