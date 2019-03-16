#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};

class Path {
public:
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if(a == b) return true;
        return check(a, b) || check(b, a);
    }

    bool check(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        // "queue" to store node that will be reached
        queue<UndirectedGraphNode*> Queue({a});

        // "set" to store reached node
        unordered_set<UndirectedGraphNode*> set({a});
        while(!Queue.empty()) {
            UndirectedGraphNode* tmp = Queue.front();
            Queue.pop();
            if(tmp == NULL) continue;
            for(auto &i : tmp->neighbors){
                if(i == b) return true;
                else if(!set.count(i)){ 
                    Queue.push(i);
                    set.insert(i);
                }
            }
        }
        return false;
    }
};