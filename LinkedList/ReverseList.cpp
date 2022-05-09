#include <iostream>

using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *current, ListNode *prev, ListNode *head)
    {
        if (current == nullptr)
        {
            head = prev;
            return head;
        }
        head = reverse(current->next, current, head);
        current->next = prev;
        return head;
    }

    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *prev = nullptr, *current = head;
        return reverse(current, prev, head);
    }

    void Display(ListNode *head)
    {
        while(head) {
            cout << head -> val << " ";
            head = head->next;
        }
        cout << endl;
    }
};


int main() {
    Solution s;
    ListNode *l = new ListNode(10);
    l->next = new ListNode(20);
    l->next->next = new ListNode(30);

    l = s.reverseList(l);
    s.Display(l);

    return 0;
}

