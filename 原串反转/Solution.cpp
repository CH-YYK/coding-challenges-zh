#include <string>
#include <iostream>
using namespace std;

class Reverse {
public:
    string reverseString(string iniString) {
        int i = 0, j = iniString.size()-1;
        while(i < j)
            swap(iniString[i++], iniString[j--]);
        return iniString;
    }
};

int main() {
    string iniString("hello world");
    string ans = Reverse().reverseString(iniString);
    cout << ans << "\n";
    return 0;
}