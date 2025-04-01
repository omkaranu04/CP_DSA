#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int insertions = 0;
    int position = 1;

    for (char c : s)
    {
        if (position % 2 == 1)
        {
            if (c == 'o')
            {
                insertions++;
                position++;
            }
        }
        else
        {
            if (c == 'i')
            {
                insertions++;
                position++;
            }
        }
        position++;
    }

    if (position % 2 == 0)
    {
        insertions++;
    }

    cout << insertions << endl;

    return 0;
}