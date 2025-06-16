#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *n1, ListNode *n2)
{
    ListNode head(0);
    ListNode *tail = &head;
    int carry = 0;
    while (n1 || n2 || carry)
    {
        int x = n1 ? n1->val : 0;
        int y = n2 ? n2->val : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        sum %= 10;

        tail->next = new ListNode(sum);
        tail = tail->next;

        if (n1)
            n1 = n1->next;
        if (n2)
            n2 = n2->next;
    }

    return head.next;
}

ListNode *GetList(string &num)
{
    ListNode *n1 = nullptr;
    ListNode *head = nullptr;
    for (int i = (int)num.length() - 1; i >= 0; i--)
    {
        ListNode *temp = new ListNode(num[i] - '0');
        if (n1)
        {
            n1->next = temp;
            n1 = temp;
        }
        else
        {
            n1 = temp;
            head = n1;
        }
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string num1, num2;
    cin >> num1;
    cin >> num2;

    ListNode *n1 = GetList(num1);
    ListNode *n2 = GetList(num2);

    ListNode *sum = addTwoNumbers(n1, n2);

    string ans = "";
    while (sum)
    {
        ans += ('0' + sum->val);
        sum = sum->next;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    return 0;
}
