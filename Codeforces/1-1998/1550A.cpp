#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    int output[t];
    for (int i = 0; i < t; i++)
    {
        int s, count = 0, j = 1;
        cin >> s;
        while (j * j < s)
            j++;
        output[i] = j;
    }
    for (int k = 0; k < t; k++)
    {
        cout << output[k] << endl;
    }

    return 0;
}
