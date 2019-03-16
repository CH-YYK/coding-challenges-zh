#include <vector>
using namespace std;

class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
        for(int i = 0; i < n/2; i++) {
            for(int j = i; j < n-i -1; j++) {
                int tmp = mat[i][j];
                mat[i][j] = mat[n-1-j][i];
                mat[n-1-j][i] = mat[n-1-i][n-1-j];
                mat[n-i-1][n-j-1] = mat[j][n-i-1];
                mat[j][n-i-1] = tmp;
            }
        }
        return mat;
    }
};

