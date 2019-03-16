#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Subset {
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        size = n;
        sort(A.begin(), A.end(), [](const int x, const int y){return x > y;});
        dfs(A, 0, subset);
        return all_subsets;
    }

private:
    int size;
    vector<vector<int>> all_subsets;
    vector<int> subset;

    void dfs(vector<int> &A, int i, vector<int> subset) {
        if(i >= size){
            if(subset.size() > 0) {
                
                all_subsets.push_back(subset);
            }
            return;
        }
        subset.push_back(A[i]);
        dfs(A, i+1, subset);
        subset.pop_back();
        dfs(A, i+1, subset);
    }
};

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    int n = 5;
    vector<vector<int>> ans = Subset().getSubsets(A, n);
    for(auto &i : ans) {
        for(auto &j : i) 
            cout << j << " ";
        cout << "\n";
    }
    return 0;        
}