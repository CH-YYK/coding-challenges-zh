#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Permutation {
public:
    vector<string> getPermutation(string A) {
        // sort(A.begin(), A.end(), [](const char x, const char y){return x > y;});
        int index = 1 << A.size();
        vector<string> permutation = dfs(A, index);
        sort(permutation.begin(), permutation.end(), greater<string>());
        return permutation;
    }
private:
    vector<string> dfs(string &A, int index) {
        if(index & (index + 1) == 0){
            return vector<string>({});
        };
        vector<string> res;
        string base;
        for(int i = 0; i < A.size(); i++) {
            if((index & (1 << i)) > 0) continue;
            vector<string> tmp = dfs(A, index | (1 << i));
            if(tmp.size() > 0) {
                for(string &j : tmp) 
                    res.push_back(base + A[i] + j);
            }else{
                res.push_back(base + A[i]);
            }
        }
        return res;
    }   
};

class Permutation2 {
public:
    vector<string> getPermutation(string A) {
        vector<string> res;
        if(A.size() == 0)
            return res;
        permutation(A, res, 0);
        sort(res.begin(), res.end(), greater<string>());//排序
        return res;
    }
 
    void permutation(string A, vector<string>& res, int cur){
        int len = A.size();
        if(cur == len -1){//到最后一个字符，就插入结果
            res.push_back(A);
            return;
        }
        for(int i = cur; i < len; ++i){
            swap(A[i], A[cur]);//交换元素
            permutation(A, res, cur+1);//递归调用
            swap(A[i], A[cur]);//换回来
        }
    }
};


int main() {
    string A = "XXN";
    vector<string> ans = Permutation().getPermutation(A);
    for(string &i : ans) {
        for(char &j : i)
            cout << j << " ";
        cout << "\n";
    }
    return 0;
}