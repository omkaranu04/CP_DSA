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

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *nhead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return nhead;
}
void reorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;

    ListNode *oddhead = head;
    ListNode *even = head->next;
    ListNode *evenhead = head->next;

    while (even && even->next)
    {
        oddhead->next = even->next;
        oddhead = oddhead->next;
        even->next = oddhead->next;
        even = even->next;
    }
    oddhead->next = NULL;

    evenhead = reverseList(evenhead);
    oddhead->next = evenhead;
}

ListNode *GetList(vector<int> &num)
{
    ListNode *head = nullptr;

    if (num.empty())
    {
        return head;
    }

    ListNode *cur = head;

    for (int i = 0; i < (int)num.size(); i++)
    {
        ListNode *temp = new ListNode(num[i]);
        if (!cur)
        {
            cur = temp;
            head = cur;
        }
        else
        {
            cur->next = temp;
            cur = temp;
        }
    }

    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
    }

    ListNode *head = GetList(num);

    reorderList(head);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";

    return 0;
}
