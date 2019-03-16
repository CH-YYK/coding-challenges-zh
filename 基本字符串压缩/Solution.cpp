#include <string>
#include <iostream>
using namespace std;

class Zipper {
public:
    string zipString(string iniString) {
        string zippedString;
        int i = 0;
        while(i < iniString.size()-1) {
            int j = 1; 
            while(iniString[i++] == iniString[i])
                j++;
            zippedString += iniString[i-1];
            zippedString += to_string(j);
        }
        return zippedString.size() > iniString.size() ? iniString : zippedString;
    }
};

int main() {
    string iniString = "abcdeeeeeeee";
    string ans = Zipper().zipString(iniString);
    cout << ans << "\n";
}