#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        if(n % 2 != 0) return false;
        stack<char> Stack;
        for(int i = 0; i < n; i++) {
            if(A[i] != '(' && A[i] != ')') return false;
            if(A[i] == '(') Stack.push(i);
            else {
                if(Stack.empty()) return false;
                else Stack.pop();
            }
        }
        return Stack.empty();
    }
};

int main() {
    string A = "()a()()";
    int n = 7;
    bool ans = Parenthesis().chkParenthesis(A, n);
    cout << ans << "\n";
    return 0;
}