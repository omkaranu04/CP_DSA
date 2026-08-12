#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int arr[26] = {0}, count = 0;
    for (int i = 0; i < size(s); i++)
    {
        arr[s[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
            count++;
    }
    if (count % 2 != 0)
        cout << "IGNORE HIM!" << endl;
    else
        cout << "CHAT WITH HER!" << endl;
    return 0;
}
