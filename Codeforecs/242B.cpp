#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int l[n], r[n];
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (l[i] < min)
            min = l[i];
        if (r[i] > max)
            max = r[i];
    }
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (l[i] == min && r[i] == max)
            index = i + 1;
    }
    cout << index << endl;
    return 0;
}