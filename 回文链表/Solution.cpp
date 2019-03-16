#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        ListNode* newNode = new ListNode(pHead->val);
        ListNode* curr = newNode;
        ListNode* pre = NULL;
        while(pHead != NULL) {
            curr->next = new ListNode(pHead->val);
            curr = curr->next;

            ListNode* tmp = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = tmp;    
        }
        newNode = newNode->next;
        while(newNode && pre) {
            if(newNode->val != pre->val) return false;
            newNode = newNode->next;
            pre = pre->next;
        }
        return true;
    }
};

int main() {
    ListNode* pHead = new ListNode(0), *curr = pHead;
    for(auto &i : {1, 2, 3, 2, 1}) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    pHead = pHead->next;
    bool ans = Palindrome().isPalindrome(pHead);
    cout << ans << "\n";
    return 0;
}