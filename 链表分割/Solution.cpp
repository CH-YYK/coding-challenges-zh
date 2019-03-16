#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead == NULL) return NULL;
        ListNode* Large = new ListNode(0);
        ListNode* l = Large;
        ListNode* Small = new ListNode(0);
        ListNode* s = Small;

        while(pHead != NULL) {
            ListNode* tmp = pHead->next;
            pHead->next = NULL;
            if(pHead->val < x){
                s->next = pHead;
                s = s->next;
            }else{
                l->next = pHead;
                l = l->next; 
            }
            pHead = tmp;
        }
        s->next = Large->next;
        return Small->next;
    }
};

int main() {
    ListNode* pHead = new ListNode(0);
    ListNode* curr = pHead;
    for(auto &i : {5,4,3,2,1}) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    pHead = pHead->next;

    ListNode* ans = Partition().partition(pHead, 3);
    while(ans != NULL) {
        cout << ans->val << " ";
        ans = ans->next; 
    }
    cout << "\n";
}