#include <iostream> 
#include <string>
#include <math.h>
using namespace std;

class BinDecimal {
public:
    string printBin(double num) {
        string res = "0.";
        int n = 1;
        while(num > 0) {
            if(num >= pow(2, -n)) {
                res += "1";
                num -= pow(2, -n);
            } else 
                res += "0";
            n++;
        }
        if(n <= 32) return res;
        else return "Error";
    }
};