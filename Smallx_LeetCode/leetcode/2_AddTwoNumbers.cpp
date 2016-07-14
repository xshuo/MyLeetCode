#ifdef __2__

#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret, *temp;
        ret = temp = NULL;
        int add = 0, sum = 0;
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + add;
            ListNode* n_node = new ListNode(sum % 10);
            add = sum / 10;
            if (ret == NULL) {
                ret = temp = n_node;
            } else {
                temp->next = n_node;
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* list;
        if (l1 != NULL) {
            list = l1;
        } else {
            list = l2;
        }
        while (list != NULL) {
            sum = list->val + add;
            ListNode* n_node = new ListNode(sum % 10);
            add = sum / 10;
            if (ret == NULL) {
                ret = temp = n_node;
            } else {
                temp->next = n_node;
                temp = temp->next;
            }
            list = list->next;
        }
        if (add != 0) {
            ListNode* n_node = new ListNode(add);
            temp->next = n_node;
            temp = temp->next;
        }
        return ret;
    }
};

int main(int argc, char** args) {
    ListNode* l1, *l2, *temp;
    l1 = l2 = NULL;
    temp = NULL;
    ListNode* n_node = new ListNode(3);
    l1 = temp = n_node;
    n_node = new ListNode(7);
    temp->next = n_node;
    temp = temp->next;
    //n_node = new ListNode(3);
    //temp->next = n_node;
    //temp = temp->next;
    //n_node = new ListNode(9);
    //temp->next = n_node;
    //temp = temp->next;

    n_node = new ListNode(9);
    l2 = temp = n_node;
    n_node = new ListNode(2);
    temp->next = n_node;
    temp = temp->next;
    //n_node = new ListNode(4);
    //temp->next = n_node;
    //temp = temp->next;
    //n_node = new ListNode(1);
    //temp->next = n_node;
    //temp = temp->next;
    //n_node = new ListNode(8);
    //temp->next = n_node;
    //temp = temp->next;

    (new Solution())->addTwoNumbers(l1, l2);
    return 1;
}

#endif