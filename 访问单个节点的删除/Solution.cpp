#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Remove {
public:
    bool removeNode(ListNode* pNode) {
        if(pNode == NULL) return false;
        if(pNode->next == NULL) return false;
        pNode = pNode->next;
        return true;
    }
};