#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool found = false;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
            {
                cout << i + 1 << endl;
                found = true;
            }
        }
        if (found == false)
        {
            if (arr[0] != arr[1])
                cout << 1 << endl;
            else
                cout << n << endl;
        }
    }
    return 0;
}
