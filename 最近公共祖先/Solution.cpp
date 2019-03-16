#include <iostream>
using namespace std;

class LCA {
public:
    int getLCA(int a, int b) {
        if(b > a) return lca(a, b);
        else return lca(b, a);
    }

    int lca(int min, int max) {
        if(min == max) return min;
        while(max > min) {
            max /= 2;
        }
        return lca(max, min);
    }
};