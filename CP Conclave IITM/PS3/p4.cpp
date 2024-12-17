#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, flag = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            flag++;
    }
    if (flag == 0)
        cout << "EASY";
    else
        cout << "HARD";
    return 0;
}
