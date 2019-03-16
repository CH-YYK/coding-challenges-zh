#include <string>
#include <iostream>
using namespace std;

class ReverseEqual {
    // C++ check substring, s1.find(s2)
public:
    bool checkReverseEqual(string s1, string s2) {
        int i = 0, j = 0;
        if(s1.size() == 0 || s2.size() == 0) return false;
        s1.append(s1);
        if(s1.find(s2) == -1) return false;
        else return true;
    }
};