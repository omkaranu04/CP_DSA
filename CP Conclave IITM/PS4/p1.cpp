#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    int output[t];
    for (int i = 0; i < t; i++)
    {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        output[i] = arr[1];
    }
    for (int i = 0; i < t; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}