#include <bits/stdc++.h>
using namespace std;

string multiply(const string &num1, const string &num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";
    vector<int> result(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; --i)
    {
        for (int j = num2.size() - 1; j >= 0; --j)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + mul;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string product;
    for (int digit : result)
    {
        if (!product.empty() || digit != 0)
            product += (digit + '0');
    }
    return product.empty() ? "0" : product;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    unordered_map<string, int> freq;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    long long count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            string product = multiply(a[i], a[j]);
            if (freq.count(product))
            {
                count += freq[product];
            }
        }
    }

    cout << count << "\n";
    return 0;
}