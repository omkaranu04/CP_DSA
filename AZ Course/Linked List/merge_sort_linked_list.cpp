
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

ListNode *merge(ListNode *a, ListNode *b)
{
    ListNode dummy;
    ListNode *tail = &dummy;
    while (a && b)
    {
        if (a->val <= b->val)
        {
            tail->next = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a ? a : b);
    return dummy.next;
}

ListNode *mergesort(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = NULL;

    ListNode *l = mergesort(head);
    ListNode *r = mergesort(mid);

    return merge(l, r);
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
    head = mergesort(head);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";

    return 0;
}
