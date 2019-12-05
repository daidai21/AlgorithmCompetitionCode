# https://www.lintcode.com/problem/sort-integers/description


class Solution:
    """
    @param A: an integer array
    @return: nothing
    """
    def sortIntegers(self, A):
        # write your code here
        for i in range(len(A)):
            newVal = A[i]
            j = i - 1
            while j >= 0 and A[j] > newVal:
                A[j + 1] = A[j]
                j -= 1
            A[j + 1] = newVal
        return A

