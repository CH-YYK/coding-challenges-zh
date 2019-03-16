#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Same {
public:
    bool checkSam(string stringA, string stringB) {
        unordered_map<char, int> map;
        for(char &i : stringA) {
            if(map.count(i)) map[i]++;
            else map[i] = 1;
        }

        for(char &j:stringB){
            if(!map.count(j) || map[j] <= 0) return false;
            else map[j]--;
        }
        return true;
    }
};

int main() {
    string stringA = "This is ";
    string stringB = "is This ";
    bool ans = Same().checkSam(stringA, stringB);
    cout << ans << "\n";
    return 0;
}