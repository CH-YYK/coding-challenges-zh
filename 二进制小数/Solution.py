# -*- coding:utf-8 -*-
class BinDecimal:
    # repeatedly append "0" or "1" to res string
    def printBin(self, num):
        res = ""
        n = 0
        while num > 0:
            if num < 2 ** -n:
                res += "0"
            else:
                res += "1"
                num -= 2 ** -n
            n += 1
        if n <= 32:
            return res[0] + "." + res[1:]
        return "Error"

if __name__ == "__main__":
    print(BinDecimal().printBin(0.625))
        