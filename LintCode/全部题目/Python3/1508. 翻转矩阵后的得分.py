class Solution:
    """
    @param A: a matrix
    @return: the score
    """
    def matrixScore(self, A):
        # Write your code here.

        # row move
        for i in range(len(A)):
            if A[i][0] == 0:
                for j in range(len(A[0])):
                    A[i][j] = 1 - A[i][j]
        # column move
        for i in range(len(A[0])):
            n1, n0 = 0, 0
            for j in range(len(A)):
                if A[j][i] == 1:
                    n1 += 1
                else:
                    n0 += 1
            if n1 < n0:
                for j in range(len(A)):
                    A[j][i] = 1 - A[j][i]
        # ans
        ans = 0
        for i in A:
            tmp = 0
            for j in i:
                tmp = tmp * 2 + j
            ans += tmp
        return ans
