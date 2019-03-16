#include <vector>
#include <iostream>
using namespace std;

class MagicIndex {
    // Binary search
public:
    bool findMagicIndex(vector<int> A, int n) {
        int l = 0, r = A.size()-1;
        while(l < r) {
            int m = (l + r) / 2;
            if(A[m] == m) return true;
            else if(A[m] > m) r = m;
            else l = m + 1;
        }
        return false;
    }
};