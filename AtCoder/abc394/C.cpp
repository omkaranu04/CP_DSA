#include <iostream>
#include <string>
using namespace std;

string replaceWSequence(string s)
{
    string result;
    int countW = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'W')
        {
            countW++;
        }
        else if (s[i] == 'A' && countW > 0)
        {
            result += 'A';
            result.append(countW, 'C');
            countW = 0;
        }
        else
        {
            result.append(countW, 'W');
            countW = 0;
            result += s[i];
        }
    }
    result.append(countW, 'W');
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    cout << replaceWSequence(S) << endl;

    return 0;
}