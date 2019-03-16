#include <vector>
#include <iostream>
using namespace std;

class MagicIndex {
    // Binary search
public:
    bool findMagicIndex(vector<int> A, int n) {
        return dfs(A, 0, A.size()-1);
    }

    bool dfs(vector<int> &A, int l, int r) {
        if(l <= r){
            int m = (l+r) / 2;
            if(A[m] == m) 
                return true;
            else 
                return dfs(A, l, min(m-1, A[m])) || dfs(A, max(l, m+1), r);
        } 
        return false;
    }
};