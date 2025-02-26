#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, freq[26] = {0}, i;
        string s;
        cin >> a >> s;
        for (i = 0; i < a; i++)
        {
            freq[s[i] - 'a']++;
        }
        int max = 0, maxindex = 0;
        for (i = 0; i < 26; i++)
        {
            if (freq[i] > max)
            {
                max = freq[i];
                maxindex = i;
            }
        }
        char c = maxindex + 'a';
        cout << c << endl;
    }
    return 0;
}
