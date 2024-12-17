#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int n, q;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int max = arr[0];
        q = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                q = i;
            }
        }
        double f_a = max, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != q)
                sum += arr[i];
        }
        double f_b = sum / (double)(n - 1);
        cout << fixed << setprecision(9) << f_a + f_b << endl;
    }
    return 0;
}
