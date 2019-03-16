#include <string>
#include <iostream>
using namespace std;

class Replacement {
    // O(N) in time, O(N) in space
public:
    string replaceSpace(string iniString, int length) {
        string newstring;
        for(char &i : iniString) {
            if(i == ' ') 
                newstring += "%20";
            else
                newstring += i;           
        }
        return newstring;   
    }
};

class Replacement2 {
    // O(N) in time, O(N) in space
public:
    string replaceSpace(string iniString, int length) {
        int numZero = 0;
        for(int i = 0; i < length; i++) 
            numZero += iniString[i] == ' ' ? 1 : 0;
        
        iniString.append(string(2*numZero, ' '));

        int i1 = length-1, i2 = length + 2 * numZero - 1;
        while(i2 >= i1 && i1 >= 0) {
            if(iniString[i1] != ' ')
                iniString[i2--] = iniString[i1--];
            else{
                iniString[i2--] = '0';
                iniString[i2--] = '2';
                iniString[i2--] = '%';
                i1--;            
            }
        }
        return iniString;
    }
};


int main() {
    string iniString = "Hello  world";
    string ans = Replacement2().replaceSpace(iniString, 12);
    cout << ans << "\n";
    return 0;
}