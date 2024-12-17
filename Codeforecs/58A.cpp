#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string word;
    cin >> word;
    string hello = "hello";
    int j = 0, pas = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == hello[j])
        {
            j++;
            pas++;
        }
    }
    if (pas == 5)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
    return 0;
}