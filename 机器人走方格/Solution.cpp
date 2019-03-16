#include <vector>
#include <iostream>
using namespace std;

class Robot {
public:
    int countWays(int x, int y) {
        vector<vector<int>> memo(x, vector<int>(y, 0));
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                if(i == 0 || j == 0)
                    memo[i][j] = 1;
                else
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        return memo[x-1][y-1];
    }
};