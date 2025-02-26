#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, count = 0;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] != arr[i])
            count++;
    }
    cout << count;
    return 0;
}
