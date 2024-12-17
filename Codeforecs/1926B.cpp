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
        vector<string> arr;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            arr.push_back(s);
        }
        bool t = false;
        for (int i = 0; i < n; i++)
        {
            int rowcount = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == '1')
                    rowcount++;
            }
            if (rowcount == 1)
                t = true;
            else if (rowcount > 1)
                break;
        }
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            int rowcount = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == '1')
                    rowcount++;
            }
            if (rowcount == 1)
                t = true;
            else if (rowcount > 1)
                break;
        }
        if (t)
            cout << "TRIANGLE" << endl;
        else
            cout << "SQUARE" << endl;
    }
    return 0;
}