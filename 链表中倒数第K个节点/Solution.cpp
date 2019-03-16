#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
    // remember the corner cases.
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* curr = pListHead;
        int i = 0;
        while(pListHead != NULL) {
            if(i >= k) {
                curr = curr->next;
            }
            pListHead = pListHead->next;
            i++;
        }
        if(i < k) return NULL;
        return curr;
    }
};