#include <vector>
#include <iostream>
using namespace std;

class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {
        if(x % 2 == 0) return vector<int>({x >> 1, x << 1});
        else return vector<int>({(x+1) >> 1, x+1});
    }
};

int main() {
    int x = 5;
    vector<int> ans = CloseNumber().getCloseNumber(x);
    for(auto &i : ans) cout << i << "\n";
    return 0;
}