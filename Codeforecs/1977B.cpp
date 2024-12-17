#include <iostream>
#include <vector>

using namespace std;

vector<int> findArray(int x)
{
    vector<int> arr;
    int n = 0;
    while (x != 0)
    {
        arr.push_back(x % 2);
        x /= 2;
        n++;
    }
    return arr;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        vector<int> arr = findArray(x);
        cout << arr.size() << endl;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}