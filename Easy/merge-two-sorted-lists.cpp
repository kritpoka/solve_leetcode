#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* buffer = new ListNode(0);
        ListNode* curr = buffer;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        curr->next = list1 ? list1 : list2;

        return buffer = buffer->next;
    }
};

ListNode* createList(const vector<int>& vals) {
    if(vals.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;

    for(size_t i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }

    return head;
}

int main() {
    Solution solution;

    ListNode* l1 = createList({1, 2, 4});
    ListNode* l2 = createList({1, 3, 4});

    ListNode* ans = solution.mergeTwoLists(l1, l2);

    while(ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}