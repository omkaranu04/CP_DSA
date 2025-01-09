#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<bool> arr(n + 1, true);

    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
            cout << i << endl;
    }

    return 0;
}