#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, h;
    cin >> n >> h;
    int arr[n], width = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= h)
            width += 1;
        else
            width += 2;
    }
    cout << width;
    return 0;
}
