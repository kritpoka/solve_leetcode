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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *reverse = new ListNode(0);
        ListNode *curr = reverse;

        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = 0;
            sum += carry; 

            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            carry = sum / 10;
        }

        // cout << reverse << endl;

        return reverse->next;
    }
};

int main(){
    Solution solution;

    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *list = solution.addTwoNumbers(l1, l2);
    ListNode *curr = list;

    while(curr != nullptr){
        cout << curr->val << endl;
        curr = curr->next;
    }   

    return 0;
}