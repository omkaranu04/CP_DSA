#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heights(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> heights[i];
        }
        unordered_map<int, int> frequency;
        for (int height : heights)
        {
            frequency[height]++;
        }
        int max_occurrences = 0;
        int max_height = 0;
        for (const auto &entry : frequency)
        {
            if (entry.second > max_occurrences)
            {
                max_occurrences = entry.second;
                max_height = entry.first;
            }
        }
        int operations = 0;
        for (int height : heights)
        {
            if (height != max_height)
            {
                operations++;
            }
        }
        cout << operations << endl;
    }
    return 0;
}