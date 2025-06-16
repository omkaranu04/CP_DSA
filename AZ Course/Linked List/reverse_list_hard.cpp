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
    ListNode *curr = head;
    ListNode *prev = NULL, *nnext = NULL;
    while (curr)
    {
        nnext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nnext;
    }
    head = prev;
    return head;
}

ListNode *reverseList(ListNode *head, int K)
{
    if (head == NULL || K == 1)
        return head;
    ListNode *curr = head, *newHead = NULL, *prevTail = NULL;
    while (curr)
    {
        ListNode *tail = curr;
        for (int i = 1; i < K && tail != NULL; i++)
            tail = tail->next;
        if (tail == NULL)
            break;
        ListNode *nextHead = tail->next;
        tail->next = NULL;
        ListNode *revHead = revList(curr);
        if (newHead == NULL)
            newHead = revHead;
        else
            prevTail->next = revHead;
        prevTail = curr;
        curr = nextHead;
    }
    if (prevTail != NULL)
        prevTail->next = curr;
    return newHead;
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

    int K;
    cin >> K;

    ListNode *head = GetList(num);

    head = reverseList(head, K);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";

    return 0;
}
