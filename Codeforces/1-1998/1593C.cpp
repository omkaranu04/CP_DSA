#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k;
        cin >> n >> k;
        long long int x[k];
        for (int i = 0; i < k; i++)
        {
            cin >> x[i];
        }
        sort(x, x + k);
        reverse(x, x + k);
        long long int cat_pos = 0, saved = 0;
        for (int i = 0; i < k; i++)
        {
            if (cat_pos < x[i])
            {
                cat_pos += (n - x[i]);
                saved++;
            }
            else
                break;
        }
        cout << saved << endl;
    }
    return 0;
}