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
ListNode *revList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *nhead = revList(head->next);
    head->next->next = head;
    head->next = NULL;
    return nhead;
}
void reorderList(ListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    // Step 1 -> split in middle
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Step 2 -> reverse the second half
    ListNode *halfbegin = slow->next;
    slow->next = NULL;
    halfbegin = revList(halfbegin);
    // Step 3 -> alternate merge
    ListNode *p1 = head, *p2 = halfbegin;
    while (p1 && p2)
    {
        ListNode *n1 = p1->next, *n2 = p2->next;
        p1->next = p2;
        p2->next = n1;

        p1 = n1;
        p2 = n2;
    }
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
