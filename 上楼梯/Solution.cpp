#include <vector>
#include <iostream>

class GoUpstairs {
    // 数值溢出 overflow
public:
    int countWays(int n) {
        vector<int>memo(n+1, 0);
        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 4;
        for(int i = 4; i <= n; i++) {
            memo[i] = ((memo[i-1] + memo[i-2]) % 1000000007 + memo[i-3]) % 1000000007;
        }
        return memo[n];
    }
};
