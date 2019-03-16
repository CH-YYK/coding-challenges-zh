#include <iostream>
using namespace std;

class Transform {
public:
    int calcCost(int A, int B) {
        // write code here
        int C = A ^ B;
        int n = 0;

        // keep removing the leftmost 1
        while(C > 0) {
            C &= (C-1);
            n++;
        }
        return n;
    }
};