# -*- coding:utf-8 -*-
class Transform:
    def transformImage(self, mat, n):
        for i in range(n//2):
            for j in range(i, n-i-1):
                tmp = mat[i][j]
                mat[i][j] = mat[n-1-j][i]
                mat[n-1-j][i] = mat[n-1-i][n-1-j]
                mat[n-1-i][n-1-j] = mat[j][n-1-i]
                mat[j][n-1-i] = tmp
        return mat

if __name__ == "__main__":
    mat = [[1,2,3],[4,5,6],[7,8,9]]
    print(Transform().transformImage(mat, 3))
    print(3//2)
