#include <vector>
using namespace std;

class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        vector<vector<int>>dp(x, vector<int>(y, 0));
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++) {
                if(map[i][j] != 1) continue;
                if(i == 0 && j == 0) dp[i][j] = 1;
                if(i == 0 && j != 0) 
                    dp[i][j] = dp[i][j-1];
                if(j == 0 && i != 0)
                    dp[i][j] = dp[i-1][j];
                if(i > 0 && j > 0) 
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
            }
        }
        return dp[x-1][y-1];
    }
};