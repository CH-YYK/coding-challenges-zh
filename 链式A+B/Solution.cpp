#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        ListNode* newNode = new ListNode(0);
        ListNode* curr = newNode;
        int ind = 0;
        while(a || b) {
            curr->next = new ListNode(ind);
            curr = curr->next;
            if(a != NULL && b != NULL){
                curr->val += b->val + a->val;
                a = a->next;
                b = b->next;
            } else if(a != NULL) {
                curr->val += a->val;
                a = a->next;
            } else if(b != NULL) {
                curr->val += b->val;
                b = b->next;
            }
            ind = curr->val / 10;
            curr->val %= 10;
        }
        if(ind > 0) curr->next = new ListNode(ind);
        return newNode->next;
    }
};